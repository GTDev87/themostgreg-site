let component = ReasonReact.statelessComponent("Page_Index");

[%bs.raw {|require('@react-website-themes/default/styles/variables')|}];
[%bs.raw {|require('@react-website-themes/default/styles/global')|}];

let make = (~props: PagePropType.props, _children) => {
  ...component,
  render: _self =>
    <div>
      <Intro />
      <Menu />
      <Hero heroHTML=props##data##hero##html />
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
    </div>,
  /* </Layout> */
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(~props=jsProps##props, [||])
  );