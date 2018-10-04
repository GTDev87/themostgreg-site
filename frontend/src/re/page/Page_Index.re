let component = ReasonReact.statelessComponent("Page_Index");

[%bs.raw {|require('../../../../../src/styles/styles.css')|}];
[%bs.raw {|require('@react-website-themes/default/styles/variables')|}];
[%bs.raw {|require('@react-website-themes/default/styles/global')|}];

let make = (~props: PagePropType.props, _children) => {
  ...component,
  render: _self => {
    Js.log("props##data");
    Js.log(props##data);
    <div>
      <Intro />
      <Menu />
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