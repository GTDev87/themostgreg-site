let component = ReasonReact.statelessComponent("Page_404");

[%bs.raw {|require('@react-website-themes/default/styles/variables')|}];
[%bs.raw {|require('@react-website-themes/default/styles/global')|}];

let make = (~props, _children) => {
  ...component,
  render: _self =>
    <Layout>
      <Header>
        <Branding
          title=Config.config##headerTitle
          subTitle=Config.config##headerSubTitle
        />
        <Menu items=Config.menu />
      </Header>
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
    </Layout>,
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(~props=jsProps##props, [||])
  );