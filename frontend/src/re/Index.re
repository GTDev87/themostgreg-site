let component = ReasonReact.statelessComponent("Index");

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
      ~heroHTML: Js.Option.t('string),
      ~footerLinksHTML: Js.Option.t('string),
      ~copyrightHTML: Js.Option.t('string),
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
      <Hero heroHTML />
      <Footer links=footerLinksHTML copyright=copyrightHTML />
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
    make(
      ~heroHTML=Js.Nullable.toOption(jsProps##heroHTML),
      ~footerLinksHTML=Js.Nullable.toOption(jsProps##footerLinksHTML),
      ~copyrightHTML=Js.Nullable.toOption(jsProps##copyrightHTML),
      [||],
    )
  );