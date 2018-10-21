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
  mb-4
  `)
  |}
];

let projectModalImageClass = [%bs.raw
  {| css(tw`
  flex
  space-between
  `)
  |}
];

let projectModalTitleClass = [%bs.raw
  {| css(tw`
    flex
    justify-between
  `)
  |}
];

let projectModalTextCategoriesClass = [%bs.raw {| css(tw`
  inline
  `)
  |}];

let projectModalTextContentClass = [%bs.raw {| css(tw`
    p-8
    `)
    |}];

let joinStringList = (listString: list(string), glue: string): string =>
  Belt.List.reduce(listString, "", (memo, ele) =>
    memo ++ (memo == "" ? ele : glue ++ ele)
  );

let make = (~project, _children) => {
  ...component,
  render: _self =>
    <div className=projectModalContentClass>
      <div className=projectModalImageClass> <ProjectCover project /> </div>
      <div className=projectModalTextContentClass>
        <div className=projectModalTitleClass>
          <h3> {ReasonReact.string(project##node##frontmatter##title)} </h3>
          <div>
            <h4 className=projectModalTextCategoriesClass>
              {ReasonReact.string("Categories: ")}
            </h4>
            {
              project##node##frontmatter##categories
              |> Belt.List.fromArray
              |> joinStringList(_, ", ")
              |> ReasonReact.string
            }
          </div>
        </div>
        <div className=projectModalDividerClass />
        <p> {ReasonReact.string(project##node##excerpt)} </p>
      </div>
    </div>,
};