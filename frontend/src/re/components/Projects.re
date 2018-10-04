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

let make = (~projects, _children) => {
  ...component,
  render: _self =>
    <div className=projectsClass>
      <Section title="Projects">
        <div className=projectsContainerClass>
          {
            projects##edges
            |> Belt.Array.map(_, edge =>
                 <div className=projectCoverImageClass>
                   <ProjectCover project=edge##node />
                 </div>
               )
            |> ReasonReact.array
          }
        </div>
      </Section>
    </div>,
};