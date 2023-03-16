# BigInt

## Your Task

You are required to update the UML Class diagram in this file to match your
submitted BigInt class. For full marks your UML diagram must exactly match your
source code. Be sure to indicate private members (both functions and variables).

## UML Class Diagram

```plantuml
skinparam class {
  BackgroundColor none
  BorderColor Black
  AttributeIconSize 0
}

hide circle

class BigInt {

  {static} + PRECISION: const int
  - digit: typedef int  
  - digits: digit[]
  - invalid: bool
  - overflow: bool


  - init (const string&) : void
  + BigInt ()
  + BigInt (const char[])
  + BigInt (const &string)
  + BigInt (long)
  + length () const : int
  + isOverflow() const : bool
  + isInvalid() const : bool
  + toString() const : string
  + add (const BigInt&) const : BigInt
  + add (long) const : BigInt
  + compare (const BigInt&) const: int
  + compare (long) const: int
  + greaterThan (const BigInt&) const: bool
  + greaterThan (long) const: bool
  + greaterThanOrEqual (const BigInt&) const: bool
  + greaterThanOrEqual (long) const: bool
  + lessThan (const BigInt&) const: bool
  + lessThan (long) const: bool
  + lessThanOrEqual (const BigInt&) const: bool
  + lessThanOrEqual (long) const: bool
  + equal (const BigInt&) const: bool
  + equal (long) const: bool
  + notEqual (const BigInt&) const: bool
  + notEqual (long) const: bool
}
```

## A Brief Introduction to Markdown

*[adapted from:https://www.markdowntutorial.com]*

**Markdown** is a way to write content for the web. It’s written in
“plaintext”, which is exactly the sort of text you’re used to writing and
seeing. Plaintext is just the regular alphabet, with a few familiar symbols,
like asterisks ( * ) and backticks ( ` ).

Unlike cumbersome word processing applications, text written in Markdown can be
easily shared between computers, mobile phones, and people. It’s quickly
becoming a writing standard for software developers. Websites like GitLab,
GitHub and reddit use Markdown to style their comments.

Formatting text in Markdown has a very gentle learning curve. It doesn’t do
anything fancy like change the font size, color, or type. All you have control
over is the display of the text—stuff like making things bold, creating
headers, and organizing lists.

If you have ten minutes, you can learn Markdown! See
https://www.markdowntutorial.com

For GitLab specific markdown information see:
https://docs.gitlab.com/ee/user/markdown.html

## A Brief Introduction to PlantUML

*[adapted from: http://plantuml.com]*

**PlantUML** is used to *draw* UML diagrams, using a simple and human readable
text description. Be careful, because it does not prevent you from drawing
inconsistent diagrams (such as having two classes inheriting from each other,
for example). So it's more a **drawing** tool than a **modeling** tool.

GitLab & PlantUML provide a powerful way to document software right inside the
repo. You can see that the UML Class diagram is stored inside of the git
repository. It will have all of the benefits of source code tracking.

For a full description of UML Class Diagrams in PlantUML visit:
http://plantuml.com/class-diagram

You can ***play*** with the UML diagram provided above by visiting:
https://cs.kingsu.ca/plantuml/uml/U9njZZqFWZ0GXlV-YfkCXiMPJOr35p4o6eTIAboihMbFJ2JyTskBaO7nxdc__0tDGpXn1wc5zniYXzMJ59VMbFXMi6Oi4jXYmmr1pnX0xqaGoW6ousc_uoKl3Za4XoT0Grz5DigNg-cH9B8LxdoP0GiVsaqJYLQceJRunzmy9WU0lkYKkshxch3AMfqWDvtGMCymicMCdw3K5_UAklxDIACMVrbwC3Qm3-ZVNvC0
