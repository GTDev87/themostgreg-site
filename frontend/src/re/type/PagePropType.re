type imageType = {. "publicURL": string};

type frontmatterType = {
  .
  "title": string,
  "categories": array(string),
  "cover": imageType,
  "images": array(imageType),
};

type fieldType = {
  .
  "slug": string,
  "prefix": string,
};
type htmlType = {
  .
  "id": string,
  "html": string,
  "frontmatter": frontmatterType,
  "fields": fieldType,
  "excerpt": string,
};

type nodeType = {
  .
  "id": string,
  "categories": array(string),
  "excerpt": string,
  "frontmatter": frontmatterType,
  "fields": fieldType,
};

type edge = {. "node": nodeType};

type postType = {
  .
  "edges": array(edge),
  "totalCount": int,
};

type dataProp = {
  .
  "projects": postType,
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