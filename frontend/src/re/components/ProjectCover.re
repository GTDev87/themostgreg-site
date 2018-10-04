let component = ReasonReact.statelessComponent("ProjectCover");

let css = Css.css;
let tw = Css.tw;

let projectCoverClass = [%bs.raw
  {| css(tw`
  border-solid
  border-grey
  hover:border-teal
  h-full
`)
|}
];

let projectCoverImageClass = [%bs.raw {| css(tw`
  w-full
  `)
  |}];

let make = (~project, _children) => {
  ...component,
  render: _self =>
    <div className=projectCoverClass>
      <img
        className=projectCoverImageClass
        src=project##frontmatter##cover##publicURL
      />
    </div>,
};