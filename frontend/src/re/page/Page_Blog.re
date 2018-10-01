let component = ReasonReact.statelessComponent("Page_Blog");

type metaIcons = {
  .
  "calendar": ReasonReact.reactClass,
  "user": ReasonReact.reactClass,
  "tag": ReasonReact.reactClass,
};

let metaIcons = {
  "calendar": CalendarIcon.comp,
  "user": UserIcon.comp,
  "tag": TagIcon.comp,
};

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
        <Blog
          items={
            props##data##posts##edges |> Belt.Array.map(_, edge => edge##node)
          }
          author="greg"
          metaIcons
        />
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