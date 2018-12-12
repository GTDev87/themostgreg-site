import { graphql } from 'gatsby';
import React from 'react';

import Page from '../../lib/es6_global/src/re/template/Template_Post.bs.js';

export default (props) => {
  console.log("Page = ", Page)
  console.log("props = ", props)
  return <Page props={props} />
};

/* TODO MDX can't use named queries https://github.com/ChristopherBiscardi/gatsby-mdx/issues/202 */

export const pageQuery = graphql`
  query($slug: String!) {
    post: mdx(fields: { slug: { eq: $slug } }) {
      html
      code {
        scope
        body
      }
      fileAbsolutePath
      excerpt
      fields {
        slug
        prefix
      }
      frontmatter {
        title
        categories
      }
    }
    author: mdx(
      fileAbsolutePath: { regex: "/content/parts/author/" }
    ) {
      html
      code {
        scope
        body
      }
    }
    footerLinks: mdx(
      fileAbsolutePath: { regex: "/content/parts/footerLinks/" }
    ) {
      html
      code {
        scope
        body
      }
    }
    copyright: mdx(
      fileAbsolutePath: { regex: "/content/parts/copyright/" }
    ) {
      html
      code {
        scope
        body
      }
    }
  }
`;
