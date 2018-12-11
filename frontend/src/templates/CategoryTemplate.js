import { graphql } from 'gatsby';
import React from 'react';
import { withMDXScope } from "gatsby-mdx/context";

import Page from '../../lib/es6_global/src/re/template/Template_Category.bs.js';

const MDXPage = withMDXScope(Page);

export default (props) => <MDXPage props={props} />;

export const query = graphql`
  query CategoryTemplateQuery($category: String!) {
    posts: allMdx(
      limit: 1000
      sort: { fields: [fields___prefix], order: DESC }
      filter: { frontmatter: { categories: { eq: $category } } }
    ) {
      totalCount
      edges {
        node {
          fields {
            slug
          }
          excerpt
          timeToRead
          frontmatter {
            title
            categories
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
