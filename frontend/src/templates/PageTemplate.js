import { graphql } from 'gatsby';
import React from 'react';

import Page from '../../lib/es6_global/src/re/template/Template_Page.bs.js';

export default (props) => {
  console.log("Page = ", Page)
  console.log("props = ", props)
  return <Page props={props} />
};

/* TODO MDX can't use named queries https://github.com/ChristopherBiscardi/gatsby-mdx/issues/202 */

export const pageQuery = graphql`
  query($slug: String!) {
    page: mdx(fields: { slug: { eq: $slug } }) {
      html
      code {
        scope
        body
      }
      excerpt
      fileAbsolutePath
      fields {
        slug
        prefix
      }
      frontmatter {
        title
        categories
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
