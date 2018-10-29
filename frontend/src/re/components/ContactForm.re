let component = ReasonReact.statelessComponent("ContactForm");

let css = Css.css;
let tw = Css.tw;

let emailClass = [%bs.raw
  {| css(tw`
  flex
  w-full
  bg-black
  text-white
  mb-4
`)
|}
];

let messageClass = [%bs.raw
  {| css(tw`
  flex
  w-full
  mb-4
  bg-black
  text-white
  h-48
`)
|}
];

let buttonClass = [%bs.raw
  {| css(tw`
  bg-grey-darkest
    text-white
    border-solid
    text-xl
    py-2
    px-4
    hover:bg-teal
    hover:text-white
    border-2
    no-underline
`)
|}
];

let formClass = [%bs.raw {| css(tw`
  w-1/3
`)
|}];

let make = _children => {
  ...component,
  render: _self =>
    <form
      method="POST"
      action="https://formspree.io/gregt87@gmail.com"
      className=formClass>
      <input
        type_="email"
        name="email"
        placeholder="Your email"
        className=emailClass
      />
      <textarea
        name="message"
        placeholder="Your message"
        className=messageClass
      />
      <button type_="submit" className=buttonClass>
        {ReasonReact.string("Send")}
      </button>
    </form>,
};