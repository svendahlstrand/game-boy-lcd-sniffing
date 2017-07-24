# Sniff your Game Boy's LCD using a logic analyzer

**or How to Take Screenshots the Hard Way.**

So, you want to immortalize your Tetris high score for future generations? You could do it the easy way and snap a photo of the screen with your smartphone. Or, gasp, take a screenshot when playing on an emulator.

But what fun is that?

Wouldn't it be cool to crack open your old brick, peek at the LCD data bus and extract the screenshot from there? Let's do it!

![](images/intro.jpg)

## Before you begin

You'll need a handful of stuff to get started:

* An [Original Game Boy][dmg] to play with.

* A [tri-point screwdriver][screwdriver] to open the Game Boy.

* The [Saleae Logic 8][saleae] logic analyzer.

* [Logic Software][logic] for capturing and analyzing the data.

This guide assumes you are using Saleae's logic analyzer and software, but you don't have to. Use any logic analyzer and software you want.

I think you will be able to follow along fine nevertheless, but you may have to deviate from my instructions from time to time.

## Open up your Game Boy

Opening up the Game Boy is easy! Once you've got hold of a tri-point screwdriver, that's it.

![](images/screws.jpg)

There are six screws on the back that needs loosing: four along the edges and two that you will find hiding behind the batteries, once you've removed them.

## Connect test clips to data bus

When the Game Boys guts are exposed, you will see that the back and front PCBs are connected with a ribbon cable.

![](images/connections.jpg)

You're going to tap into the connector on the back PCB using test clips of your Logic 8. If you squint your eyes hard enough, you may see that the contacts of the connector are numbered 1-21.

Attach test clips to contact number 12, 14, 15, 16, 17 and 21 using the table below. Test clip number 3 (orange cable) goes to contact number 12 (V-Sync), and so on.


|   Test clip:   |      3      |      4      |      0      |      1      |      2      |    Ground   |
| :------------: | :---------: | :---------: | :---------: | :---------: | :---------: | :---------: |
|                |    Orange   |   Yellow    |    Black    |    Brown    |     Red     |    Black    |
|  **Contact:**  |    **12**   |    **14**   |    **15**   |    **16**   |    **17**   |    **21**   |
|                |    V‑Sync   | Pixel Clock |  LCD Data 0 |  LCD Data 1 |    H‑Sync   |    Ground   |

When you are done attaching test clips, it should look something like this.

![](images/test-clips.jpg)

### Those signals, what are they?

* Roughly explain V-Sync et al.

## Record them ones and zeroes

Now when you're all hooked up, it's time to connect the Logic 8 to your computer and fire up the Logic Software.

* Show a screenshot of my setup and link to the configuration.

* Briefly explain the process.

* Show example export.

## Extract a screenshot

* Now you have the raw data. You can convert manually or use my program.

* Link to my exported recorded data (for testing and verification).

* Short explanation of PGM.

## ~~Common~~ My  mistakes

* have to inverse colors
* falling edge, not rising.
* mixed up data 0 and data 1

Show the screenshots.

[dmg]: https://en.wikipedia.org/wiki/Game_Boy
[screwdriver]: https://en.wikipedia.org/wiki/List_of_screw_drives#Tri-point
[saleae]: https://www.saleae.com
[logic]: https://www.saleae.com/downloads
