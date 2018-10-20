let component = ReasonReact.statelessComponent("Page_Index");

[%bs.raw {|require('../../../../../src/styles/styles.css')|}];
[%bs.raw {|require('@react-website-themes/default/styles/variables')|}];
[%bs.raw {|require('@react-website-themes/default/styles/global')|}];

let css = Css.css;
let tw = Css.tw;
let introAreaCss = [%bs.raw
  {| css(tw`
    h-screen
    flex
    flex-col
  `) |}
];

let introAreaClass = [%bs.raw
  {| css(tw`
    h-screen
    flex
    flex-col
  `) |}
];

let heroAreaClass = [%bs.raw
  {| css(tw`
    /* this is remaning space*/
    flex-1
    `)
  |}
];

let menuAreaClass = [%bs.raw {| css(tw`
  flex-no-grow
`) |}];

let make = (~props: PagePropType.props, _children) => {
  ...component,
  render: _self => {
    Js.log("props##data");
    Js.log(props##data);
    <div>
      <div className=introAreaClass>
        <div className=heroAreaClass> <Intro /> </div>
        <div className=menuAreaClass> <Menu /> </div>
      </div>
      <About />
      <Projects projects=props##data##projects />
      <Footer
        links=props##data##footerLinks##html
        copyright=props##data##copyright##html
      />
      <Seo
        url=Config.config##siteUrl
        language=Config.config##siteLanguage
        title=Config.config##siteTitle
        description=Config.config##siteDescription
      />
    </div>;
  },
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(~props=jsProps##props, [||])
  );