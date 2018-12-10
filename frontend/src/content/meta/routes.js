const path = require('path');

const postTemplate = path.resolve('./src/templates/PostTemplate.js');
const pageTemplate = path.resolve('./src/templates/PageTemplate.js');

const routesArray = [
  {path: "parts"},
  {
    path: "posts",
    template: postTemplate,
    context: (edge, index, edges) => {
      const slug = edge.node.fields.slug;
      const next = index === 0 ? undefined : edges[index - 1].node;
      const prev =
        index === edges.length - 1 ? undefined : edges[index + 1].node;
      return {
        slug,
        prev,
        next
      };
    }
  },
  {
    path: "pages",
    template: pageTemplate,
    context: (edge) => {
      const slug = edge.node.fields.slug;
      const source = edge.node.fields.source;
      return {
        slug,
        source,
      };
    },
  },
  {path: "projects"},
  {
    path: "proposals",
    template: pageTemplate,
    context: (edge) => {
      const slug = edge.node.fields.slug;
      const source = edge.node.fields.source;
      return {
        slug,
        source,
      };
    },
  },
];

module.exports = { routesArray };