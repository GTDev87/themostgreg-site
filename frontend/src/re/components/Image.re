let component = ReasonReact.statelessComponent("Image");

let css = Css.css;
let tw = Css.tw;

let imageClass = [%bs.raw {| css(tw`
  w-full
  flex
  justify-center
`)
|}];

let jpgClass = [%bs.raw
  {| css(tw`
  bg-no-repeat
  w-full
  h-full
  rounded-full
  bg-contain
  `)
  |}
];

let make = _children => {
  ...component,
  render: _self =>
    <div className=imageClass>
      <CircleInfo
        size=LG
        label="Who is Greg?"
        copy="Freelancer, Developer, Coach, Consultant, Climber, Traceur, Dog Lober.  I have a passion and borderline obession with optimizing process."
        comp={<div className={jpgClass ++ " bg-greg-image"} />}
      />
    </div>,
};