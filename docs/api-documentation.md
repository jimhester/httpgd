# `httpgd` API documentation

<!-- copy to: vignette/api-documentation.Rmd -->

[httpgd](https://github.com/nx10/httpgd/blob/master/README.md) can be accessed both from R and from HTTP/WebSockets.

## Overview

| R                                   | HTTP                           | Description                         |
| ----------------------------------- | ------------------------------ | ----------------------------------- |
| `hgd()`                             |                                | Initialize device and start server. |
| `hgd_close()`                       |                                | Helper: Close device.               |
| `hgd_url()`                         |                                | Helper: URL generation.             |
| `hgd_browse()`                      |                                | Helper: Open browser.               |
| [`hgd_state()`](#get-state)         | [`/state`](#get-state)         | Get current server state.           |
| [`hgd_renderers()`](#get-renderers) | [`/renderers`](#get-renderers) | Get list of available renderers.    |
| ~~[`hgd_svg()`](#render-svg)~~      | ~~[`/svg`](#render-svg)~~      | Get rendered SVG. (Deprecated)      |
| [`hgd_plot()`](#render-plot)        | [`/plot`](#render-plot)        | Get rendered plot (any format).     |
| [`hgd_clear()`](#remove-plots)      | [`/clear`](#remove-plots)      | Remove all plots.                   |
| [`hgd_remove()`](#remove-plots)     | [`/remove`](#remove-plots)     | Remove a single plot.               |
| [`hgd_id()`](#get-static-ids)       | [`/plots`](#get-static-ids)    | Get static plot IDs.                |
|                                     | `/`                            | Welcome message.                    |
|                                     | `/live`                        | Live server page.                   |

## Get state

While all the APIs can be accessed stateless, the graphics device does have a state defined by.

| Field    | Type   | Description                                                                                                                                                                             |
| -------- | ------ | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| `upid`   | `int`  | Update id. Changes when plots are removed or when something is drawn.                                                                                                                   |
| `hsize`  | `int`  | Number of plots in the history.                                                                                                                                                         |
| `active` | `bool` | Whether the graphics device is active. When another graphics device is activated, the device will become inactive and not be able to render any plots that are not cached (no resizes). |

To receive state changes as they happen [WebSockets can be used](#from-websockets). Alternatively `/state` may be polled repeatedly.

### From R

```R
hgd_state()
```

Will respond with a list object including fields containing `host`, `port` and security `token` of the server.

### From HTTP

```
/state
```

| Key     | Value                        | Default                                                 |
| ------- | ---------------------------- | ------------------------------------------------------- |
| `token` | [Security token](#security). | (The `X-HTTPGD-TOKEN` header can be set alternatively.) |

Will respond with a JSON object.

### From WebSockets

httpgd accepts WebSocket connections on the same port as the HTTP server. [Server state](#Server-state) changes will be broadcasted immediately to all connected clients in JSON format. 

## Get Renderers

httpgd includes multiple renderers that can dynamically render plots to different target formats. As new formats may be added as the development on httpgd continues, and some depend on optional system dependencies, a list of available renderers can be obtained during runtime.

The following is a complete list of renderers. Note that some may not yet be available in the release version of httpgd:

| ID        | Mime-Type                | Renderer                                                 | Format | Depends |
| --------- | ------------------------ | -------------------------------------------------------- | ------ | ------- |
| `svg`     | `image/svg+xml`          | Scalable Vector Graphics (SVG).                          | string |         |
| `svgp`    | `image/svg+xml`          | Version of the SVG renderer that produces portable SVGs. | string |         |
| `json`    | `application/json`       | Plot data serialized to JSON format.                     | string |         |
| `png`     | `image/png`              | Portable Network Graphics (PNG).                         | binary | Cairo   |
| `pdf`     | `application/pdf`        | Adobe Portable Document Format (PDF).                    | binary | Cairo   |
| `ps`      | `application/postscript` | PostScript (PS).                                         | string | Cairo   |
| `eps`     | `application/postscript` | Encapsulated PostScript (EPS).                           | string | Cairo   |
| `tikz`    | `text/plain`             | LaTeX TikZ code.                                         | string |         |
| `strings` | `text/plain`             | List of plot strings.                                    | string |         |
| `meta`    | `application/json`       | Plot meta information.                                   | string |         |


### From R

```R
hgd_renderers()
```

Will respond with a list object.

### From HTTP

```
/renderers
```

| Key     | Value                        | Default                                                 |
| ------- | ---------------------------- | ------------------------------------------------------- |
| `token` | [Security token](#security). | (The `X-HTTPGD-TOKEN` header can be set alternatively.) |

## Render plot

Plots can be rendered in various file formats from both R and HTTP. The actual plot construction in R is relatively slow so httpgd caches the plot in the last requested size. Subsequent calls with the same width and height or without a size specified will always be fast. (This way "flipping" through plot pages is very fast.)

### From R

Example:
```R
hgd_plot(page = 3, width = 800, height = 600) # Get plot at index 3 with 800*600
hgd_plot() # Get last plot with cached size
```

`page` can either be a number to indicate a plot index or a static plot ID (see: hgd_id()).

This function returns the plot as a string. The `file` attribute can be used to save the SVG directly to disk.

### From HTTP

Example:
```
/plot?index=2&width=800&height=600
```

Parameters:

| Key        | Value                        | Default                                                 |
| ---------- | ---------------------------- | ------------------------------------------------------- |
| `width`    | With in pixels.              | Last rendered width. (Initially device width.)          |
| `height`   | Height in pixels.            | Last rendered height. (Initially device height.)        |
| `zoom`     | Zoom level.                  | `1` (No zoom). `0.5` would be 50% and `2` 200%.         |
| `index`    | Plot history index.          | Newest plot.                                            |
| `id`       | Static plot ID.              | `index` will be used.                                   |
| `renderer` | Renderer.                    | `svg`.                                                  |
| `token`    | [Security token](#security). | (The `X-HTTPGD-TOKEN` header can be set alternatively.) |

> Note that the HTTP API uses 0-based indexing and the R API 1-based indexing. This is done to conform to R and JavaScript on both ends. (This means the the first plot is accessed with `/svg?index=0` and `hgd_svg(page = 1)`.)

## Render SVG

> **This API is deprecated and will be removed in the future.**

`hgd_svg()` and `/svg` are equivalent to [`hgd_plot()`](#render-plot) and [`/plot`](#render-plot) as the default renderer is SVG. 



## Remove plots

### From R

Examples:
```R
hgd_remove(page = 2) # Remove the second page
hgd_clear() # Clear all pages
```

### From HTTP

Examples:
```
/remove?index=2
/clear
```

| Key     | Value                        | Default                                                 |
| ------- | ---------------------------- | ------------------------------------------------------- |
| `index` | Plot history index.          | Newest plot.                                            |
| `id`    | Static plot ID.              | `index` will be used.                                   |
| `token` | [Security token](#security). | (The `X-HTTPGD-TOKEN` header can be set alternatively.) |


## Get static IDs

The problem with requesting individual plots by index is, that a plots index will change when earlier plots are removed from the plot history.
To circumvent this, each plot also is assigned a static ID. 

All APIs that access individual plots can also be called with static IDs instead of indices.

### From R

Examples:
```R
hgd_id(index = 2) # Static ID of the second plot
hgd_id() # Static ID of the last plot
```

Note: The `limit` parameter can be adjusted to obtain multiple or all plot IDs.

### From HTTP

Examples:
```
/plots?index=2
/plots
```

| Key     | Value                          | Default                                                 |
| ------- | ------------------------------ | ------------------------------------------------------- |
| `index` | Plot history index.            | Newest plot.                                            |
| `limit` | Number of subsequent plot IDs. | 1                                                       |
| `token` | [Security token](#security).   | (The `X-HTTPGD-TOKEN` header can be set alternatively.) |


Notes: 

- The `limit` parameter can be specified to support pagination.
- The JSON response will contain the [state](#get-state) to allow checking for desynchronisation.

## Security

A security token can be set when starting the device:

```R
hgd(..., token = "secret")
```

When set, each API request has to include this token inside the header `X-HTTPGD-TOKEN` or as a query param `?token=secret`.
`token` is by default set to `TRUE` to generate a random 8 character alphanumeric token. If it is set to a number, a random token of that length will be generated. `FALSE` deactivates the security token.

CORS is off by default but can be enabled on startup:

```R
hgd(..., cors = TRUE)
```
