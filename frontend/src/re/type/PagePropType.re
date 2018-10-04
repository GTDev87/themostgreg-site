type categoryType;

type frontmatterType = {
  .
  "title": string,
  "categories": array(categoryType),
};
type fieldType = {
  .
  "slug": string,
  "prefix": string,
};
type htmlType = {
  .
  "html": string,
  "frontmatter": frontmatterType,
  "fields": fieldType,
  "excerpt": string,
};
type nodeType;
type edge = {. "node": nodeType};

type postType = {
  .
  "edges": array(edge),
  "totalCount": int,
};

type dataProp = {
  .
  "posts": postType,
  "post": htmlType,
  "footerLinks": htmlType,
  "copyright": htmlType,
  "notFound": htmlType,
  "page": htmlType,
  "author": htmlType,
};

type linkType;

type pageContextType = {
  .
  "category": string,
  "next": linkType,
  "prev": linkType,
};

type props = {
  .
  "data": dataProp,
  "pageContext": pageContextType,
};

type metaIconsType = {
  .
  "calendar": ReasonReact.reactClass,
  "user": ReasonReact.reactClass,
  "tag": ReasonReact.reactClass,
};

let metaIcons: metaIconsType = {
  "calendar": CalendarIcon.comp,
  "user": UserIcon.comp,
  "tag": TagIcon.comp,
};