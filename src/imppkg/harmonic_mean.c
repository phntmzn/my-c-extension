#define PY_SSIZE_T_CLEAN
#include <Python.h>

static PyObject* harmonic_mean(PyObject* self, PyObject* args) {
    PyObject* list;
    if (!PyArg_ParseTuple(args, "O!", &PyList_Type, &list)) {
        return NULL;
    }

    Py_ssize_t size = PyList_Size(list);
    if (size == 0) {
        PyErr_SetString(PyExc_ValueError, "Empty list");
        return NULL;
    }

    double reciprocal_sum = 0.0;
    for (Py_ssize_t i = 0; i < size; ++i) {
        PyObject* item = PyList_GetItem(list, i);  // Borrowed reference
        double val = PyFloat_AsDouble(item);
        if (val == 0.0) {
            PyErr_SetString(PyExc_ZeroDivisionError, "Zero in input");
            return NULL;
        }
        reciprocal_sum += 1.0 / val;
    }

    double result = size / reciprocal_sum;
    return PyFloat_FromDouble(result);
}

static PyMethodDef Methods[] = {
    {"harmonic_mean", harmonic_mean, METH_VARARGS, "Calculate harmonic mean"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef moduledef = {
    PyModuleDef_HEAD_INIT,
    "harmonic_mean",   // Module name
    NULL,              // Docstring
    -1,
    Methods
};

PyMODINIT_FUNC PyInit_harmonic_mean(void) {
    return PyModule_Create(&moduledef);
}
