import React from 'react';
import { graphql } from 'gatsby';

import '@react-website-themes/default/styles/variables';
import '@react-website-themes/default/styles/global';

import Index from '../../lib/es6_global/src/re/Index.bs.js';

const IndexPage = props => {
  return <Index props={props} />;
};

export default IndexPage;

export const query = graphql`
  query {
    hero: markdownRemark(fileAbsolutePath: { regex: "/content/parts/hero/" }) {
      html
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
