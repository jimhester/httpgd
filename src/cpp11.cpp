// Generated by cpp11: do not edit by hand
// clang-format off


#include "cpp11/declarations.hpp"

// Httpgd.cpp
bool httpgd_(std::string host, int port, std::string bg, double width, double height, double pointsize, cpp11::list aliases, bool cors, std::string token, bool webserver, bool silent, bool fix_text_width, std::string extra_css);
extern "C" SEXP _httpgd_httpgd_(SEXP host, SEXP port, SEXP bg, SEXP width, SEXP height, SEXP pointsize, SEXP aliases, SEXP cors, SEXP token, SEXP webserver, SEXP silent, SEXP fix_text_width, SEXP extra_css) {
  BEGIN_CPP11
    return cpp11::as_sexp(httpgd_(cpp11::as_cpp<cpp11::decay_t<std::string>>(host), cpp11::as_cpp<cpp11::decay_t<int>>(port), cpp11::as_cpp<cpp11::decay_t<std::string>>(bg), cpp11::as_cpp<cpp11::decay_t<double>>(width), cpp11::as_cpp<cpp11::decay_t<double>>(height), cpp11::as_cpp<cpp11::decay_t<double>>(pointsize), cpp11::as_cpp<cpp11::decay_t<cpp11::list>>(aliases), cpp11::as_cpp<cpp11::decay_t<bool>>(cors), cpp11::as_cpp<cpp11::decay_t<std::string>>(token), cpp11::as_cpp<cpp11::decay_t<bool>>(webserver), cpp11::as_cpp<cpp11::decay_t<bool>>(silent), cpp11::as_cpp<cpp11::decay_t<bool>>(fix_text_width), cpp11::as_cpp<cpp11::decay_t<std::string>>(extra_css)));
  END_CPP11
}
// Httpgd.cpp
cpp11::list httpgd_state_(int devnum);
extern "C" SEXP _httpgd_httpgd_state_(SEXP devnum) {
  BEGIN_CPP11
    return cpp11::as_sexp(httpgd_state_(cpp11::as_cpp<cpp11::decay_t<int>>(devnum)));
  END_CPP11
}
// Httpgd.cpp
cpp11::list httpgd_renderers_(int devnum);
extern "C" SEXP _httpgd_httpgd_renderers_(SEXP devnum) {
  BEGIN_CPP11
    return cpp11::as_sexp(httpgd_renderers_(cpp11::as_cpp<cpp11::decay_t<int>>(devnum)));
  END_CPP11
}
// Httpgd.cpp
std::string httpgd_random_token_(int len);
extern "C" SEXP _httpgd_httpgd_random_token_(SEXP len) {
  BEGIN_CPP11
    return cpp11::as_sexp(httpgd_random_token_(cpp11::as_cpp<cpp11::decay_t<int>>(len)));
  END_CPP11
}
// Httpgd.cpp
bool httpgd_renderer_is_str_(std::string renderer_id);
extern "C" SEXP _httpgd_httpgd_renderer_is_str_(SEXP renderer_id) {
  BEGIN_CPP11
    return cpp11::as_sexp(httpgd_renderer_is_str_(cpp11::as_cpp<cpp11::decay_t<std::string>>(renderer_id)));
  END_CPP11
}
// Httpgd.cpp
bool httpgd_renderer_is_raw_(std::string renderer_id);
extern "C" SEXP _httpgd_httpgd_renderer_is_raw_(SEXP renderer_id) {
  BEGIN_CPP11
    return cpp11::as_sexp(httpgd_renderer_is_raw_(cpp11::as_cpp<cpp11::decay_t<std::string>>(renderer_id)));
  END_CPP11
}
// Httpgd.cpp
int httpgd_plot_find_(int devnum, std::string plot_id);
extern "C" SEXP _httpgd_httpgd_plot_find_(SEXP devnum, SEXP plot_id) {
  BEGIN_CPP11
    return cpp11::as_sexp(httpgd_plot_find_(cpp11::as_cpp<cpp11::decay_t<int>>(devnum), cpp11::as_cpp<cpp11::decay_t<std::string>>(plot_id)));
  END_CPP11
}
// Httpgd.cpp
std::string httpgd_plot_str_(int devnum, int page, double width, double height, double zoom, std::string renderer_id);
extern "C" SEXP _httpgd_httpgd_plot_str_(SEXP devnum, SEXP page, SEXP width, SEXP height, SEXP zoom, SEXP renderer_id) {
  BEGIN_CPP11
    return cpp11::as_sexp(httpgd_plot_str_(cpp11::as_cpp<cpp11::decay_t<int>>(devnum), cpp11::as_cpp<cpp11::decay_t<int>>(page), cpp11::as_cpp<cpp11::decay_t<double>>(width), cpp11::as_cpp<cpp11::decay_t<double>>(height), cpp11::as_cpp<cpp11::decay_t<double>>(zoom), cpp11::as_cpp<cpp11::decay_t<std::string>>(renderer_id)));
  END_CPP11
}
// Httpgd.cpp
cpp11::raws httpgd_plot_raw_(int devnum, int page, double width, double height, double zoom, std::string renderer_id);
extern "C" SEXP _httpgd_httpgd_plot_raw_(SEXP devnum, SEXP page, SEXP width, SEXP height, SEXP zoom, SEXP renderer_id) {
  BEGIN_CPP11
    return cpp11::as_sexp(httpgd_plot_raw_(cpp11::as_cpp<cpp11::decay_t<int>>(devnum), cpp11::as_cpp<cpp11::decay_t<int>>(page), cpp11::as_cpp<cpp11::decay_t<double>>(width), cpp11::as_cpp<cpp11::decay_t<double>>(height), cpp11::as_cpp<cpp11::decay_t<double>>(zoom), cpp11::as_cpp<cpp11::decay_t<std::string>>(renderer_id)));
  END_CPP11
}
// Httpgd.cpp
bool httpgd_remove_(int devnum, int page);
extern "C" SEXP _httpgd_httpgd_remove_(SEXP devnum, SEXP page) {
  BEGIN_CPP11
    return cpp11::as_sexp(httpgd_remove_(cpp11::as_cpp<cpp11::decay_t<int>>(devnum), cpp11::as_cpp<cpp11::decay_t<int>>(page)));
  END_CPP11
}
// Httpgd.cpp
bool httpgd_remove_id_(int devnum, std::string id);
extern "C" SEXP _httpgd_httpgd_remove_id_(SEXP devnum, SEXP id) {
  BEGIN_CPP11
    return cpp11::as_sexp(httpgd_remove_id_(cpp11::as_cpp<cpp11::decay_t<int>>(devnum), cpp11::as_cpp<cpp11::decay_t<std::string>>(id)));
  END_CPP11
}
// Httpgd.cpp
cpp11::writable::list httpgd_id_(int devnum, int page, int limit);
extern "C" SEXP _httpgd_httpgd_id_(SEXP devnum, SEXP page, SEXP limit) {
  BEGIN_CPP11
    return cpp11::as_sexp(httpgd_id_(cpp11::as_cpp<cpp11::decay_t<int>>(devnum), cpp11::as_cpp<cpp11::decay_t<int>>(page), cpp11::as_cpp<cpp11::decay_t<int>>(limit)));
  END_CPP11
}
// Httpgd.cpp
bool httpgd_clear_(int devnum);
extern "C" SEXP _httpgd_httpgd_clear_(SEXP devnum) {
  BEGIN_CPP11
    return cpp11::as_sexp(httpgd_clear_(cpp11::as_cpp<cpp11::decay_t<int>>(devnum)));
  END_CPP11
}

extern "C" {
/* .Call calls */
extern SEXP _httpgd_httpgd_(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP);
extern SEXP _httpgd_httpgd_clear_(SEXP);
extern SEXP _httpgd_httpgd_id_(SEXP, SEXP, SEXP);
extern SEXP _httpgd_httpgd_plot_find_(SEXP, SEXP);
extern SEXP _httpgd_httpgd_plot_raw_(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP);
extern SEXP _httpgd_httpgd_plot_str_(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP);
extern SEXP _httpgd_httpgd_random_token_(SEXP);
extern SEXP _httpgd_httpgd_remove_(SEXP, SEXP);
extern SEXP _httpgd_httpgd_remove_id_(SEXP, SEXP);
extern SEXP _httpgd_httpgd_renderer_is_raw_(SEXP);
extern SEXP _httpgd_httpgd_renderer_is_str_(SEXP);
extern SEXP _httpgd_httpgd_renderers_(SEXP);
extern SEXP _httpgd_httpgd_state_(SEXP);

static const R_CallMethodDef CallEntries[] = {
    {"_httpgd_httpgd_",                 (DL_FUNC) &_httpgd_httpgd_,                 13},
    {"_httpgd_httpgd_clear_",           (DL_FUNC) &_httpgd_httpgd_clear_,            1},
    {"_httpgd_httpgd_id_",              (DL_FUNC) &_httpgd_httpgd_id_,               3},
    {"_httpgd_httpgd_plot_find_",       (DL_FUNC) &_httpgd_httpgd_plot_find_,        2},
    {"_httpgd_httpgd_plot_raw_",        (DL_FUNC) &_httpgd_httpgd_plot_raw_,         6},
    {"_httpgd_httpgd_plot_str_",        (DL_FUNC) &_httpgd_httpgd_plot_str_,         6},
    {"_httpgd_httpgd_random_token_",    (DL_FUNC) &_httpgd_httpgd_random_token_,     1},
    {"_httpgd_httpgd_remove_",          (DL_FUNC) &_httpgd_httpgd_remove_,           2},
    {"_httpgd_httpgd_remove_id_",       (DL_FUNC) &_httpgd_httpgd_remove_id_,        2},
    {"_httpgd_httpgd_renderer_is_raw_", (DL_FUNC) &_httpgd_httpgd_renderer_is_raw_,  1},
    {"_httpgd_httpgd_renderer_is_str_", (DL_FUNC) &_httpgd_httpgd_renderer_is_str_,  1},
    {"_httpgd_httpgd_renderers_",       (DL_FUNC) &_httpgd_httpgd_renderers_,        1},
    {"_httpgd_httpgd_state_",           (DL_FUNC) &_httpgd_httpgd_state_,            1},
    {NULL, NULL, 0}
};
}

extern "C" void R_init_httpgd(DllInfo* dll){
  R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
  R_useDynamicSymbols(dll, FALSE);
  R_forceSymbols(dll, TRUE);
}
