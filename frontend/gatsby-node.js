const _ = require('lodash');
const path = require('path');
const Promise = require('bluebird');
const PurgeCssPlugin = require(`purgecss-webpack-plugin`);
const glob = require(`glob`);
const { createFilePath } = require(`gatsby-source-filesystem`);

const PATHS = {
  src: path.join(__dirname, `src`)
}

const SLUG_SEPARATOR = '___';

exports.onCreateBabelConfig = ({ actions: { setBabelPlugin } }) => {
  setBabelPlugin({
    name: 'babel-plugin-tailwind-components',
    options: {
      config: './tailwind.js',
      format: 'auto'
    }
  })
};

exports.onCreateNode = ({ node, getNode, actions }) => {
  const { createNodeField } = actions;
  if (node.internal.type === `MarkdownRemark`) {
    const fileNode = getNode(node.parent);
    const filePath = createFilePath({ node, getNode });

    const source = fileNode.sourceInstanceName;

    const separatorExists = ~filePath.indexOf(SLUG_SEPARATOR);

    let slug;
    let prefix;

    if (separatorExists) {
      const separatorPosition = filePath.indexOf(SLUG_SEPARATOR);
      const slugBeginning = separatorPosition + SLUG_SEPARATOR.length;
      slug =
        separatorPosition === 1
          ? null
          : `/${filePath.substring(slugBeginning)}`;
      prefix = filePath.substring(1, separatorPosition);
    } else {
      slug = filePath;
      prefix = '';
    }

    if (source !== 'parts') {
      createNodeField({
        node,
        name: `slug`,
        value: slug,
      });
    }
    createNodeField({
      node,
      name: `prefix`,
      value: prefix,
    });
    createNodeField({
      node,
      name: `source`,
      value: source,
    });
  }
};

exports.createPages = ({ graphql, actions }) => {
  const { createPage } = actions;

  return new Promise((resolve, reject) => {
    const postTemplate = path.resolve('./src/templates/PostTemplate.js');
    const pageTemplate = path.resolve('./src/templates/PageTemplate.js');
    const categoryTemplate = path.resolve(
      './src/templates/CategoryTemplate.js'
    );

    resolve(
      graphql(`
        {
          allMarkdownRemark(
            filter: { fields: { slug: { ne: null } } }
            sort: { fields: [fields___prefix], order: DESC }
            limit: 1000
          ) {
            edges {
              node {
                fileAbsolutePath
                fields {
                  slug
                  prefix
                  source
                }
                frontmatter {
                  title
                  categories
                }
              }
            }
          }
        }
      `).then(result => {
          if (result.errors) {
            console.log(result.errors);
            reject(result.errors);
          }

          const items = result.data.allMarkdownRemark.edges;

          const categorySet = new Set();

          // Create category list
          items.forEach(edge => {
            const {
              node: {
                frontmatter: { categories },
              },
            } = edge;

            if (categories) {
              categories.forEach(category => {
                categorySet.add(category);
              });
            }
          });

          // Create category pages
          const categoryList = Array.from(categorySet);
          categoryList.forEach(category => {
            createPage({
              path: `/categories/${_.kebabCase(category)}/`,
              component: categoryTemplate,
              context: {
                category,
              },
            });
          });

          // Create posts
          const posts = items.filter(item => item.node.fields.source === 'posts');
          posts.forEach(({ node }, index) => {
            const slug = node.fields.slug;
            const next = index === 0 ? undefined : posts[index - 1].node;
            const prev =
              index === posts.length - 1 ? undefined : posts[index + 1].node;

            createPage({
              path: slug,
              component: postTemplate,
              context: {
                slug,
                prev,
                next,
              },
            });
          });

          // create pages
          const pages = items.filter(item => item.node.fields.source === 'pages');
          pages.forEach(({ node }) => {
            const slug = node.fields.slug;
            const source = node.fields.source;

            createPage({
              path: slug,
              component: pageTemplate,
              context: {
                slug,
                source,
              },
            });
          });
        })
    );
  });
};

const purgeCssConfig = {
  paths: glob.sync(`${PATHS.src}/**/*.js`, { nodir: true }),
  extractors: [
    {
      // Custom extractor to allow special characters (like ":") in class names
      // See: https://tailwindcss.com/docs/controlling-file-size/#removing-unused-css-with-purgecss
      extractor: class {
        static extract(content) {
          return content.match(/[A-Za-z0-9-_:/]+/g) || []
        }
      },
      extensions: [`js`]
    }
  ],
  whitelist: [`class-to-whitelist`], // adjust for each project
  whitelistPatterns: [/body/, /headroom/, /ReactModal/, /ril/] // adjust for each project
};

exports.onCreateWebpackConfig = ({ actions, stage }) => {
  if (stage.includes(`develop`)) return

  // Add PurgeCSS in production
  // See: https://github.com/gatsbyjs/gatsby/issues/5778#issuecomment-402481270
  if (stage.includes(`build`)) {
    actions.setWebpackConfig({
      plugins: [new PurgeCssPlugin(purgeCssConfig)]
    })
  }
}