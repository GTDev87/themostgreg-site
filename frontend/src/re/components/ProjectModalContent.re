let component = ReasonReact.statelessComponent("ProjectModalContent");

let css = Css.css;
let tw = Css.tw;

let projectModalContentClass = [%bs.raw {| css(tw`
  h-full
  w-full
`)
|}];

let projectModalDividerClass = [%bs.raw
  {| css(tw`
  border-0
  border-b-2
  border-grey-light
  border-solid
  w-full
  mb-2
  `)
  |}
];

let projectModalImageClass = [%bs.raw {| css(tw`
  `)
  |}];

let projectModalTextClass = [%bs.raw {| css(tw`
  p-8
  `)
  |}];

let make = (~project, _children) => {
  ...component,
  render: _self =>
    <div className=projectModalContentClass>
      <div className=projectModalImageClass> <ProjectCover project /> </div>
      <div className=projectModalTextClass>
        <h3> {ReasonReact.string(project##node##frontmatter##title)} </h3>
        <div className=projectModalDividerClass />
        <p> {ReasonReact.string(project##node##excerpt)} </p>
      </div>
    </div>,
};