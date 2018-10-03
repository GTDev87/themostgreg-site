type styleObj;
type tailwindFn = string => styleObj;
type emotionFn = styleObj => string;

[@bs.module "emotion"] external css: emotionFn = "css";

[@bs.val] external tw: tailwindFn = "";