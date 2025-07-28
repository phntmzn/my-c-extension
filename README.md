# mycext

A simple Python package that demonstrates how to create and integrate a C extension. It provides a `square(x)` function implemented in C for performance.

## 🔧 Features

- ✅ Written in C for speed.
- ✅ Integrated with Python using `setuptools`.
- ✅ Packaged using `pyproject.toml`.

## 📦 Installation

Build and install the package locally:

```bash
git clone https://github.com/yourusername/mycext.git
cd mycext
python -m pip install .
```

## Create a virtual environment using venv

```bash
py -3.10 -m venv .venv
```

## Activate the environment

```bash
source .venv/bin/activate
```

## Upgrade pip and install dependencies
```bash
python -m pip install --upgrade pip setuptools wheel
```

## Install the package locally

```bash
python -m pip install .
```
# Quality Tooling

The passage you quoted highlights two core aspects of Python's type system:

---

### 🐍 **1. Dynamic Typing**

In Python:

- **Types are associated with values**, not variables.
- The type of a variable can change at runtime depending on the value it holds.

```python
x = 5       # x is an int
x = "five"  # now x is a str
```

No type declarations are required in advance.

---

### 🦆 **2. Duck Typing**

Python follows the **“duck typing”** philosophy:

> *"If it looks like a duck and quacks like a duck, it’s a duck."*

This means:

- Python doesn’t care about the actual class/type of an object.
- What matters is whether the object supports the **necessary methods or behaviors**.

Example:

```python
def quack(entity):
    entity.quack()

class Duck:
    def quack(self):
        print("Quack!")

class Person:
    def quack(self):
        print("I'm quacking like a duck!")

quack(Duck())    # ✅ Works
quack(Person())  # ✅ Also works, thanks to duck typing
```

Even though `Person` isn’t a `Duck`, the function works as long as the object has a `quack()` method.

---

### ✅ Why This Matters

- **Pros:**
  - Flexible and expressive code
  - Faster prototyping
- **Cons:**
  - Errors surface at runtime, not at compile time
  - Can make large codebases harder to reason about

---

### 💡 Tip: Use Type Hints

To mitigate risks in dynamic typing, Python 3 introduced **type hints**:

```python
def add(a: int, b: int) -> int:
    return a + b
```

Tools like `mypy` or editors with static analysis can then check types **before runtime**, improving reliability without losing Python’s flexibility.

Let me know if you want to see examples where duck typing leads to subtle bugs—or how to enforce structural typing with `typing.Protocol`.
