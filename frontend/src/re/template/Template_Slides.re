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
    Js.log("props##data##page = ");
    Js.log(props##data##page);
    let theme = SpectacleThemeNova.createTheme();

    let slides =
      (props##data##page##rawBody)
      |> Spectacle.markdownSlides
      |> Belt.List.fromArray
      |> Belt.List.mapWithIndex(_, (idx, value) => (idx, value))
      |> Belt.List.keep(_, ((idx, value)) => idx > 0)
      |> Belt.List.map(_, ((idx, value)) => value)
      |> Belt.List.toArray;

    <SpectacleDeck theme>
      { slides |> ReasonReact.array }
    </SpectacleDeck>
  }
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(~props=jsProps##props, [||])
  );