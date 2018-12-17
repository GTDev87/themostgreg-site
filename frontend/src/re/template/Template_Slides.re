let component = ReasonReact.statelessComponent("Template_Slides");

[%bs.raw {|require('../../../../../src/styles/styles.css')|}];
[%bs.raw {|require('prismjs/themes/prism-okaidia.css')|}];
[%bs.raw {|require('@react-website-themes/default/styles/variables')|}];
[%bs.raw {|require('@react-website-themes/default/styles/global')|}];

let css = Css.css;
let tw = Css.tw;

let defaultComponents = MDXRenderer.defaultComponents;
/* let spectacleSlidesClass = [%bs.raw {| css("") |}]; */

let make = (~props: PagePropType.props, _children) => {
  ...component,
  render: _self => {
    let theme = SpectacleThemeNova.createTheme();

    /* Note skips first page for metadata */
    /* TODO use mdx rendering when gatsby-mdx uses mdx-deck */
    <div>
      <SpectacleSlides theme markdown=props##data##page##rawBody />
    </div>
  }
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(~props=jsProps##props, [||])
  );