let component = ReasonReact.statelessComponent("Projects");

let css = Css.css;
let tw = Css.tw;

let projectsClass = [%bs.raw {| css(tw`
  px-16

`)
|}];

let projectsContainerClass = [%bs.raw
  {| css(tw`
    pt-8
    w-full
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
                   <ProjectCover project=edge />
                 </div>
               )
            |> ReasonReact.array
          }
        </div>
      </Section>
    </div>,
};