#include "polylabelfast.hpp"

namespace py = pybind11;


using namespace pybind11::literals;

PYBIND11_MODULE(polylabelfast, m)
{

    // xt::import_numpy(); // MUST import numpy here
    m.doc() = R"pbdoc(
        Pybind11 of polylabelfast
        -----------------------

        .. currentmodule:: polylabelfast

        .. autosummary::
           :toctree: _generate

    )pbdoc";

    m.def("polylabelfast", &polylabelfast::polylabelfast,
        "rings"_a, "precision"_a=1.0);


#ifdef VERSION_INFO
    m.attr("__version__") = VERSION_INFO;
#else
    m.attr("__version__") = "dev";
#endif
}
