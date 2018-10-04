let listToReactArray = list =>
  list |> Belt.List.toArray |> ReasonReact.arrayToElement;