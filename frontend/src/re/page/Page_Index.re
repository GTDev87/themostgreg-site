let component = ReasonReact.statelessComponent("Index");

[%bs.raw {|require('@react-website-themes/default/styles/variables')|}];
[%bs.raw {|require('@react-website-themes/default/styles/global')|}];

/*
module Config = [%graphql
  {|
     {
        markdownRemark(fileAbsolutePath: { regex: "/content/parts/hero/" }) {
         html
       }
       footerLinks: markdownRemark(fileAbsolutePath: { regex: "/content/parts/footerLinks/" }) {
         html
       }
       copyright: markdownRemark(fileAbsolutePath: { regex: "/content/parts/copyright/" }) {
         html
       }
     }
   |}
];
*/

let make =
    (
      ~props,
      _children,
    ) => {
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
    </Layout>
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(~props=jsProps##props, [||])
  );