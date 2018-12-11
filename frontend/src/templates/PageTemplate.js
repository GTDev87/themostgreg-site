import { graphql } from 'gatsby';
import React from 'react';
import { withMDXScope } from "gatsby-mdx/context";

import Page from '../../lib/es6_global/src/re/template/Template_Page.bs.js';

const MDXPage = withMDXScope(Page);

export default (props) => <MDXPage props={props} />;

export const query = graphql`
  query PageTemplateQuery($slug: String!) {
    page: mdx(fields: { slug: { eq: $slug } }) {
      html
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
    }
    copyright: mdx(
      fileAbsolutePath: { regex: "/content/parts/copyright/" }
    ) {
      html
    }
  }
`;
