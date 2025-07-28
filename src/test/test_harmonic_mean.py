from imppkg import harmonic_mean
import pytest

def test_basic_mean():
    assert round(harmonic_mean.harmonic_mean([1, 2, 4]), 6) == 1.714286

def test_single_element():
    assert harmonic_mean.harmonic_mean([5]) == 5.0

def test_zero_raises():
    with pytest.raises(ZeroDivisionError):
        harmonic_mean.harmonic_mean([1, 0, 2])

def test_empty_list():
    with pytest.raises(ValueError):
        harmonic_mean.harmonic_mean([])
