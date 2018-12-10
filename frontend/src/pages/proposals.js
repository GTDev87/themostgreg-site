import React from 'react';
import { graphql } from 'gatsby';

import Index from '../../lib/es6_global/src/re/page/Page_Index.bs.js';

export default (props) => <Index props={props} />;

export const query = graphql`
  query {
    projects: allMarkdownRemark(filter: {fields: {source: {eq: "proposals"}, slug: {ne: null}}}) {
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
    footerLinks: markdownRemark(
      fileAbsolutePath: { regex: "/content/parts/footerLinks/" }
    ) {
      html
    }
    copyright: markdownRemark(
      fileAbsolutePath: { regex: "/content/parts/copyright/" }
    ) {
      html
    }
  }
`;