#include <Python.h>

// Our C function: square(x)
static PyObject* square(PyObject* self, PyObject* args) {
    double input, result;
    if (!PyArg_ParseTuple(args, "d", &input)) {
        return NULL;
    }
    result = input * input;
    return Py_BuildValue("d", result);
}

// Method definitions
static PyMethodDef MyMethods[] = {
    {"square", square, METH_VARARGS, "Returns the square of a number"},
    {NULL, NULL, 0, NULL}
};

// Module definition
static struct PyModuleDef mycmodule = {
    PyModuleDef_HEAD_INIT,
    "mycmodule",
    "A simple C extension",
    -1,
    MyMethods
};

// Module init
PyMODINIT_FUNC PyInit_mycmodule(void) {
    return PyModule_Create(&mycmodule);
}
