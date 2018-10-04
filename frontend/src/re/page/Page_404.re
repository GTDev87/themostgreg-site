let component = ReasonReact.statelessComponent("Page_404");

[%bs.raw {|require('@react-website-themes/default/styles/variables')|}];
[%bs.raw {|require('@react-website-themes/default/styles/global')|}];

let make = (~props: PagePropType.props, _children) => {
  ...component,
  render: _self =>
    <div>
      <Layout>
        <Menu />
        <Article>
          <Heading title="NOT FOUND" />
          <Bodytext html_=props##data##notFound##html />
        </Article>
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
      </Layout>
    </div>,
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(~props=jsProps##props, [||])
  );