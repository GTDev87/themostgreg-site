let component = ReasonReact.statelessComponent("Template_Post");

[%bs.raw {|require('prismjs/themes/prism-okaidia.css')|}];
[%bs.raw {|require('@react-website-themes/default/styles/variables')|}];
[%bs.raw {|require('@react-website-themes/default/styles/global')|}];

let metaIcons = {
  "calendar": CalendarIcon.comp,
  "user": UserIcon.comp,
  "tag": TagIcon.comp,
};

let nextPrevIcons = {"next": NextIcon.comp, "prev": PrevIcon.comp};

let make = (~props, _children) => {
  ...component,
  render: _self => {
    let url = Config.config##siteUrl ++ props##data##post##fields##slug;
    let shareBlockProps = {
      "url": url,
      "button": ShareButtonRectangle.comp,
      "buttons": [|
        {network: "Twitter", icon: TwitterIcon.comp},
        {network: "Facebook", icon: FacebookIcon.comp},
        {network: "Email", icon: EmailIcon.comp},
      |],
      "text": props##data##post##frontmatter##title,
      "longtext": props##data##post##excerpt,
    };

    <Layout>
      <Header>
        <Branding
          title=Config.config##headerTitle
          subTitle=Config.config##headerSubTitle
        />
        <Menu items=Config.menu />
      </Header>
      <Article>
        <Heading title=props##data##post##frontmatter##title />
        <Meta
          author="greg"
          prefix=props##data##post##fields##prefix
          categories=props##data##post##frontmatter##categories
          icons=metaIcons
        />
        <Bodytext html_=props##data##post##html />
        <Share shareBlockProps />
        <NextPrev
          next=props##pageContext##next
          prev=props##pageContext##prev
          icons=nextPrevIcons
        />
        <Author html_=props##data##author##html />
        <Comments
          slug=props##data##post##fields##slug
          siteUrl=Config.config##siteUrl
        />
      </Article>
      <Footer
        links=props##data##footerLinks##html
        copyright=props##data##copyright##html
      />
      <Seo
        url={Config.config##siteUrl ++ props##data##post##fields##slug}
        language=Config.config##siteLanguage
        title={
          props##data##post##frontmatter##title
          ++
          Config.config##siteTitlePostfix
        }
        description=props##data##post##excerpt
      />
    </Layout>;
  },
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(~props=jsProps##props, [||])
  );