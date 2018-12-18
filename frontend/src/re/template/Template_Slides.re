let component = ReasonReact.statelessComponent("Template_Slides");

[%bs.raw {|require('../../../../../src/styles/styles.css')|}];
[%bs.raw {|require('prismjs/themes/prism-okaidia.css')|}];
[%bs.raw {|require('@react-website-themes/default/styles/variables')|}];
[%bs.raw {|require('@react-website-themes/default/styles/global')|}];

let css = Css.css;
let tw = Css.tw;

/* TODO: NOTE the mdx renderer may have some problems transpiling */
/* let defaultComponents = MDXRenderer.defaultComponents; */

/* let spectacleSlidesClass = [%bs.raw {| css("") |}]; */

let make = (~props: PagePropType.props, _children) => {
  ...component,
  render: _self => {
    
    /* Note skips first page for metadata */
    /* TODO use mdx rendering when gatsby-mdx uses mdx-deck */
    <div>
      <SpectacleSlides markdown=props##data##page##rawBody />
    </div>
  }
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(~props=jsProps##props, [||])
  );