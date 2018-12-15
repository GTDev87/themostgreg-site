let component = ReasonReact.statelessComponent("Template_Slides");

[%bs.raw {|require('../../../../../src/styles/styles.css')|}];
[%bs.raw {|require('prismjs/themes/prism-okaidia.css')|}];
[%bs.raw {|require('@react-website-themes/default/styles/variables')|}];
[%bs.raw {|require('@react-website-themes/default/styles/global')|}];

let css = Css.css;
let tw = Css.tw;

let defaultComponents = MDXRenderer.defaultComponents;
let layoutClass = [%bs.raw {| css(tw`my-0 text-xl leading-tight bg-blue`) |}];

let make = (~props: PagePropType.props, _children) => {
  ...component,
  render: _self => {
    let theme = SpectacleThemeNova.createTheme();

    /* Note skips first page for metadata */
    <SpectacleSlides theme markdown=props##data##page##rawBody />
  }
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(~props=jsProps##props, [||])
  );