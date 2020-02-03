# Tutorial

This document explains the first steps using bertha, i.e., how to adapt the
project skeleton to your software project.

## Setup stage

 - Define the name and goal of the project. Find a place to host your git
   repository.

 - Update the project information in the top-level `CMakeLists.txt` and the
   project goal in `README.md`. Clear the file `CHANGELOG.md` and (if
   desired) add the first stable version and its features.

 - Agree on code formatting rules. Write them down in both `.clang-format`
   and `CONTRIBUTING.md` or use what is already provided therein.

 - Agree on git work flow and update `CONTRIBUTING.md` (if required). Adapt
   the repository according to your work flow, for example:

    - Set up branches and consider protecting them (e.g., only allow
      merge by maintainer for master).

    - Set up roles of group members (maintainer, developer, ...) and
      permissions.

    - Adapt merge settings (e.g., fast-forward merge only).

    - Generate labels for issues.

    - Create first milestone(s).

    - Create first issues and assign them to milestones.

 - Adapt the `NOTICE.md` file and change the project name and description in
   lines 3-4. Leave the rest of the file as is, unless you have to add
   further projects you use within your project.

 - Consider publishing your code as open-source project. If you decide to
   do so, you will have to select an appropriate license for your project.
   Adapt the `LICENSE` file accordingly.

 - Adapt the `CODE_OF_CONDUCT.md` file as desired. Make sure to insert the
   contact information of the project team or maintainer.

 - Adapt the templates for issues and pull/merge requests for GitHub (in
   .github/) and GitLab (in .gitlab/) as desired.

 - Update the URLs of the badges in `README.md`. Note that you have to
   enable [test coverage parsing](https://docs.gitlab.com/ee/user/project/pipelines/settings.html#test-coverage-parsing) in GitLab in order to enable the
   coverage badge.

 - Set up the distribution via conda.

## Implementation stage

 - Think about the goal of your software project and a modular design that
   accomplishes this goal.

 - Use the module `core` and (optionally) create additional modules. Update
   the C++ and SWIG files accordingly.

 - Consider writing documentation first and then implementing code.

 - Consider how you can test your implementation. This will help you
   come up with a modular design (if you cannot test your implementation in
   an automated way, it is not likely to be modular).

 - Write tests and add them to the continuous integration (CI) pipeline. This
   way you can detect mistakes and regressions as soon as possible.

## Publication stage

 - Share your project as early as possible. Thereby, you can attract
   feedback from other developers, researchers, or users, which will make
   your project stronger.

 - Update the `README.md` and let people know how they can cite your work.

 - Adapt `TUTORIAL.md` and explain what should the user know at the
   beginning. Give starting points, consider adding code examples.

 - Create a recipe for your project in conda-forge. See the [conda-forge
   documentation](https://conda-forge.org/docs/maintainer/adding_pkgs.html)
   for a tutorial how to accomplish that. The recipe created for bertha
   itself may serve as reference as well. Currently, this recipe is available
   [here](https://github.com/conda-forge/staged-recipes/pull/10097).
