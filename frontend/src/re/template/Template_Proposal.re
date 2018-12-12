let component = ReasonReact.statelessComponent("Template_Proposal");

[%bs.raw {|require('../../../../../src/styles/styles.css')|}];
[%bs.raw {|require('prismjs/themes/prism-okaidia.css')|}];
[%bs.raw {|require('@react-website-themes/default/styles/variables')|}];
[%bs.raw {|require('@react-website-themes/default/styles/global')|}];

let css = Css.css;
let tw = Css.tw;

let layoutClass = [%bs.raw {| css(tw`my-0 text-xl leading-tight bg-blue`) |}];
let make = (~props: PagePropType.props, _children) => {
  ...component,
  render: _self => {
    Js.log("Template_Proposal props");
    Js.log(props);
    <div>
      <Article>
        <Heading title=props##data##page##frontmatter##title />
        <Bodytext html_=props##data##page##html />
      </Article>
    </div>
  }
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(~props=jsProps##props, [||])
  );