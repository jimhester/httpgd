# httpgd 1.2.0

- Client rewrite and static build pipeline.
- Added client export dialog.
- Various client UI improvements.
- Implemented modular rendering.
  - Cairo based renderers for PNG, PDF, EPS and PS.
  - Portable SVG renderer (for easier embedding and styling).
  - Special renderers: Serialized JSON, meta information and strings.
  - Additions to R and HTTP APIs for selecting and listing available renderers. 
- All startup default parameters can now be set as options.
- Zoom level is now handled server side.
- Fix some graphical errors of the SVG renderer.
- Improved server URL generation.
- Browser can be specified when the server URL is opened from R.
- Dependency updates and UCRT support.

# httpgd 1.1.1

- Fixed font weight related rendering crash.
- Small client adjustments.

# httpgd 1.1.0

- Added plot history sidebar.
- Improved SVG rendering performance.
- Added static plot ID API.
- Font handling improvements.
- Various client improvements.
- Added API documentation vignette.
- Fixed client device inactive desynchronisation.
- Fixes for R devel.
- Library updates.

# httpgd 1.0.1

- Fix memory allocation issues with graphics device creation and libpng.
- Set `cpp11` as a compile time only dependency.

# httpgd 1.0.0

- First official version intended for release on CRAN.