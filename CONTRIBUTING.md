# Contributing

Feel free to contribute to this project by reporting errors, requesting
features, and of course by fixing and extending the existing source code.

## Report errors or request features

Both can be accomplished by creating an issue on the project's gitlab page.
Please make sure to give a meaningful description of the issue and (in case of
an error) a minimal example that triggers the error.

## Fix or extend existing code

We follow the
[gitlab flow](https://docs.gitlab.com/ee/workflow/gitlab_flow.html)
to develop new features and maintain the existing code base. This flow can be
summarized in the following steps:

 - Every non-trivial change starts with an issue. Create one or pick an
   existing one.

 - Create a merge request with a corresponding feature branch in gitlab. Base
   the branch on "master" and (if required) adjust its name.

 - Work on the solution to the issue and push to the branch to share and
   discuss your code changes with the other developers.

 - Feel free to rearrange the commits on the feature branch (e.g., rebase
   with squash). In fact, it is your duty to provide clean and non-redundant
   commits before your code can be merged.

   Please note that it is not allowed to alter commits outside of the feature
   branches. Also, be careful when (or avoid altogether) basing your work
   on a feature branch.

   Clean commits:

    - Meaningful commit message, e.g., ".gitignore: Added generated output
      files.", "monte-carlo: Fixed indentation issue #325." The one-line commit
      message should be limited to 76 characters. If a detailed description
      is required, add a multi-line commit description.

    - Author name and e-mail are set correctly.

    - Each commit is dedicated to one particular chunk of work.

    - After each commit all continuous integration (CI) jobs pass, in
      particular the "format" job (see "Formatting" below).

    - The commits base on the latest "master" branch so that a fast-forward
      merge is possible.

 - Once you feel your code is ready, assign the merge request to a maintainer
   and remove the WIP status of the request.

 - The maintainer may decide to restart the discussion or otherwise performs
   the merge. The feature branch is removed during the merge.

## Formatting

Please follow the rules below when contributing to the project.

### General rules

 - Every line has its end. Wrap the code lines in order to improve
   readability when working in the terminal (in particular with git). The
   general limit is 78 characters. However, different languages may use or
   even require a different limit, see below.

 - Avoid git commits with whitespace changes. The general rule is to have one
   and only one newline at the end of the file and no trailing whitespaces at
   the end of line.

 - Use spaces instead of tabs. Generally, use 4 spaces per indentation.

 - Document your code as you write it. Use Doxygen annotation.

 - Make sure that the files you check in are encoded in UTF-8 and have UNIX
   style line endings (git can take care of the latter, but you may want to
   check if this setting is active).

### CMake source code rules

 - Use two spaces for indentation. No tabs.

 - Follow the conventions used in the existing code.

### C++ source code rules

 - The code formatting is based on the [Mozilla Style Guide](https://developer.mozilla.org/en-US/docs/Mozilla/Developer_guide/Coding_Style)
   The points where this style is overruled are defined in this file.

 - Use snake_case_for_names. No camelCase.

 - Use four spaces for indentation. No tabs.

 - Use C-style comments even for single lines (/* like this */).

 - The constructor initializers should look like

       my_class(many, arg, here)
         : m_many(many), m_arg(arg),
           m_here(here)

 - Run `clang-format` (or the CMake target `format`) to format the code
   automatically. It makes sense to integrate this tool into your editor.

## Creating a release

 - Summarize the changes in `CHANGELOG.md`.

 - Update version number in the top-level `CMakeLists.txt`. Make sure to
   clear the pre-release version variable.

 - Commit the changes using the commit message "Released vX.Y.Z.", where
   X, Y, and Z denote the major, minor, and patch version number. Merge the
   commit into "master".

 - Create a git tag named vX.Y.Z with the message "Version vX.Y.Z." and push
   it to the repository.

 - Optionally, create the branch "stable-X.Y.Z" and push it to the
   repository.
