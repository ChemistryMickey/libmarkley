# LibMarkley
This is a project intended to program the algorithms and models described by F. Landis Markley and John L. Crassidis in their landmark work, *Fundamentals of Spacecraft Attitude Determination and Control* (Space Technology Library, Springer).
Some additional supporting mathematics will also be provided (with sources in their respective implementations).

The reasons for doing this are enumerable:
- It's fun.
- It's good practice writing high-performance algorithms and distributing a library + headers.

While we intend this to be rigorously tested, do [please verify yourself](https://www.cs.cmu.edu/~rdriley/487/papers/Thompson_1984_ReflectionsonTrustingTrust.pdf) that the inputs and outputs are what you expect.

## Conventions and Design Decisions
Throughout this library, we use the following conventions:
- JPL convention of quaternions (i.e. scalar last); we'll also be using quaternions to represent rotations, not MRP or DCMs (though Eigen has functions which nicely convert between them).
- Units will be expressed in LaTeX/MathJax within square braces (e.g. $\left[\frac{m^{2}}{s^{3/2}}\right]$). This jibes nicely with markdown renderers even if it makes the units in code a little harder to read.
- `camelCase` will be used for variables, `snake_case` will be used for functions, `PascalCase` will be used for types, and `_<unit>` will be appended to each variable that has associated units. The unit suffix rules are "wild west as long as it's legible". Transformations will indicate `_src2dst` lest we lose track of where we are and perish.
- C++ will be the language of choice; not "C with C++ features". As such, values will be returned to minimize side-effects, templates/concepts will be used, and enums will be typed. Source and headers will be .cpp and .hpp respectively to indicate this. The `markley` namespace will also be used.
- Error handling will be through try/except so as not to force the user into any single error-handling paradigm.

For most math, rather than hand-rolling a SIMD library, we choose to use the [Eigen linear algebra library](https://libeigen.gitlab.io/).
It's fast, SIMDs by itself, and it's somewhat industry standard.
We apologize in advance for the template errors this will inevitably cause.

In order to hopefully not trip copyright, some technical information will be provided in the directories containing each alg/model but it will be neither a verbatim copy of the text nor a replacement for it.
This is a fantastic book. Get it.

## Algorithms/Models Implemented/Planned

- [x] $L_{\inf}$
- [ ] Quaternions
- [ ] Biased walk gyro noise