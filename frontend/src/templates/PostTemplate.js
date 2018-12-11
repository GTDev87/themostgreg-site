import { graphql } from 'gatsby';
import React from 'react';

import Page from '../../lib/es6_global/src/re/template/Template_Post.bs.js';
import { withMDXScope } from "gatsby-mdx/context";

const MDXPage = withMDXScope(Page);

export default (props) => <MDXPage props={props} />;

export const query = graphql`
  query PostTemplateQuery($slug: String!) {
    post: mdx(fields: { slug: { eq: $slug } }) {
      html
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
