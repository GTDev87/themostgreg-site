let component = ReasonReact.statelessComponent("Projects");

let css = Css.css;
let tw = Css.tw;

let projectsClass = [%bs.raw {| css(tw`
  px-16
  mb-4
`)
|}];

let projectsContainerClass = [%bs.raw
  {| css(tw`
    pt-8
    w-full
    h-full
    flex
    flex-wrap
    justify-center
  `)
  |}
];

let projectCoverImageClass = [%bs.raw
  {| css(tw`
      w-full
      sm:w-full
      md:w-1/2
      lg:w-1/3
      p-2
    `)
  |}
];

let projectCoverInternalImageClass = [%bs.raw
  {| css(tw`
    h-full
    border-2
    cursor-pointer
    border-solid
    border-grey-light
    hover:border-teal
    hover:opacity-75
  `)
  |}
];

let make = (~projects, ~selectProject, _children) => {
  ...component,
  render: _self =>
    <div className=projectsClass>
      <Section title="Projects">
        <div key="projects" className=projectsContainerClass>
          {
            projects
            |> Belt.Array.map(_, edge =>
                 <div
                   key=edge##node##id
                   className=projectCoverImageClass
                   onClick={_e => selectProject(edge##node##id)}>
                   <div className=projectCoverInternalImageClass>
                    <ProjectCover project=edge />
                   </div>
                 </div>
               )
            |> ReasonReact.array
          }
        </div>
      </Section>
    </div>,
};