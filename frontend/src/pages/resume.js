import React from 'react';
import { graphql } from 'gatsby';

import Page from '../../lib/es6_global/src/re/page/Page_Resume.bs.js';

let isBrowser = typeof window !== 'undefined';

export default (props) => isBrowser ? <Page props={props} /> : <div />;

export const query = graphql`
  query {
    projects: allMdx(filter: {fields: {source: {eq: "projects"}, slug: {ne: null}}}) {
      edges {
        node {
          id
          html
          excerpt(pruneLength: 250)
          fields {
            slug
            prefix
          }
          frontmatter {
            title
            categories
            cover{
              publicURL
            }
            images{
              publicURL
            }
          }
        }
      }
    }
    footerLinks: mdx(
      fileAbsolutePath: { regex: "/content/parts/footerLinks/" }
    ) {
      html
    }
    copyright: mdx(
      fileAbsolutePath: { regex: "/content/parts/copyright/" }
    ) {
      html
    }
  }
`;
