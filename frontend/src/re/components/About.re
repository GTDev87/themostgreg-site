let component = ReasonReact.statelessComponent("About");

let css = Css.css;
let tw = Css.tw;

let aboutClass = [%bs.raw {| css(tw`
  py-16
  px-16

`)
|}];

let aboutText = [%bs.raw
  {| css(tw`
  text-3xl
  w-full
  flex
  justify-center
  underline
`)
|}
];

type traits = list(Trait.trait);
let traits: traits = [
  {
    label: "Driven",
    copy: "Goes beyond what is requested.",
    icon: Edit2Icon.comp,
  },
  {
    label: "Passionate",
    copy: "Cares deeply about technology.",
    icon: Edit2Icon.comp,
  },
  {
    label: "Connected",
    copy: "Always on the clients team.",
    icon: Edit2Icon.comp,
  },
  {
    label: "Empathetic",
    copy: "Puts self into users shoes always.",
    icon: Edit2Icon.comp,
  },
];

let aboutTraitClass = [%bs.raw {| css(tw`
  md:w-1/4
`)
|}];

let aboutTraitsClass = [%bs.raw {| css(tw`
  w-full
  flex
  flex-wrap
`)
|}];

let make = _children => {
  ...component,
  render: _self =>
    <div className=aboutClass>
      <div className=aboutText> {ReasonReact.string("About")} </div>
      <div className=aboutTraitsClass>
        {
          traits
          |> Belt.List.map(_, (trait: Trait.trait) =>
               <div className=aboutTraitClass>
                 <Trait key={trait.label} trait />
               </div>
             )
          |> Utils.ReasonReact.listToReactArray
        }
      </div>
      <WhoAmI />
    </div>,
};