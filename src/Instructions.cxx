#include "../include/header/Instructions.hh"

#include <functional>
#include <unordered_map>
#include <vector>

#include "../include/header/func_wrapper.hh"
#include "../include/header/function.hh"

std::function<uniform_return(uniform_input)> Instructions::operator[](
    std::string name) {
  return this->_instructions[name];
}

std::vector<std::tuple<std::string, std::string>> Instructions::getArgs(
    std::string name) {
  return this->arguments[name];
}

std::unordered_map<std::string, std::function<uniform_return(uniform_input)>>
    Instructions::_instructions{
        {"HAD", std::bind(QB_functions::haddamard, std::placeholders::_1)},
        {"PX", std::bind(QB_functions::pauliX, std::placeholders::_1)},
        {"PY", std::bind(QB_functions::pauliY, std::placeholders::_1)},
        {"PZ", std::bind(QB_functions::pauliZ, std::placeholders::_1)},
        {"ID", std::bind(QB_functions::identity, std::placeholders::_1)},
        {"TOF", std::bind(QB_functions::toffoli, std::placeholders::_1)},
        {"RX", std::bind(QB_functions::rx, std::placeholders::_1)},
        {"RY", std::bind(QB_functions::ry, std::placeholders::_1)},
        {"RZ", std::bind(QB_functions::rz, std::placeholders::_1)},
        {"S", std::bind(QB_functions::S, std::placeholders::_1)},
        {"T", std::bind(QB_functions::T, std::placeholders::_1)},
        {"SDG", std::bind(QB_functions::S_dag, std::placeholders::_1)},
        {"TDG", std::bind(QB_functions::T_dag, std::placeholders::_1)},
        {"CY", std::bind(QB_functions::cy, std::placeholders::_1)},
        {"SWP", std::bind(QB_functions::swap, std::placeholders::_1)},
        {"MES", std::bind(QB_functions::measure, std::placeholders::_1)},
        {"GET", std::bind(QB_functions::get, std::placeholders::_1)},
        {"DHAD", std::bind(QD_functions::haddamard, std::placeholders::_1)},
        {"DCR", std::bind(QD_functions::cr, std::placeholders::_1)},
        {"DPX", std::bind(QD_functions::pauliX, std::placeholders::_1)},
        {"DPY", std::bind(QD_functions::pauliY, std::placeholders::_1)},
        {"DPZ", std::bind(QD_functions::pauliZ, std::placeholders::_1)},
        {"DID", std::bind(QD_functions::identity, std::placeholders::_1)},
        {"DTOF", std::bind(QD_functions::toffoli, std::placeholders::_1)},
        {"DRX", std::bind(QD_functions::rx, std::placeholders::_1)},
        {"DRY", std::bind(QD_functions::ry, std::placeholders::_1)},
        {"DRZ", std::bind(QD_functions::rz, std::placeholders::_1)},
        {"DS", std::bind(QD_functions::S, std::placeholders::_1)},
        {"DT", std::bind(QD_functions::T, std::placeholders::_1)},
        {"DSDG", std::bind(QD_functions::S_dag, std::placeholders::_1)},
        {"DTDG", std::bind(QD_functions::T_dag, std::placeholders::_1)},
        {"DCY", std::bind(QD_functions::cy, std::placeholders::_1)},
        {"DSWP", std::bind(QD_functions::swap, std::placeholders::_1)},
        {"DMES", std::bind(QD_functions::measure, std::placeholders::_1)},
        {"DCRK", std::bind(QD_functions::crk, std::placeholders::_1)},
        {"DGET", std::bind(QD_functions::get, std::placeholders::_1)},
    };

std::unordered_map<std::string,
                   std::vector<std::tuple<std::string, std::string>>>
    Instructions::arguments{
        {"HAD", {{"Qubit", "Qubit"}}},
        {"CR", {{"Qubit", "Qubit"}}},
        {"PX", {{"Qubit", "Qubit"}}},
        {"PY", {{"Qubit", "Qubit"}}},
        {"PZ", {{"Qubit", "Qubit"}}},
        {"ID", {{"Qubit", "Qubit"}}},
        {"TOF", {{"Qubit", "Qubit"}, {"Qubit", "Qubit"}}},
        {"RX", {{"Qubit", "Qubit"}}},
        {"RY", {{"Qubit", "Qubit"}}},
        {"RZ", {{"Qubit", "Qubit"}}},
        {"S", {{"Qubit", "Qubit"}}},
        {"T", {{"Qubit", "Qubit"}}},
        {"SDG", {{"Qubit", "Qubit"}}},
        {"TDG", {{"Qubit", "Qubit"}}},
        {"CY", {{"Qubit", "Qubit"}}},
        {"SWP", {{"Qubit", "Qubit"}, {"Qubit", "Qubit"}}},
        {"MES", {{"Qubit", "Qubit"}}},
        {"CRK", {{"Qubit", "Qubit"}}},
        {"GET", {{"Qubit", "Qubit"}}},
        {"DHAD", {{"Qubit", "Qubit"}}},
        {"DCR", {{"Qubit", "Qubit"}}},
        {"DPX", {{"Qubit", "Qubit"}}},
        {"DPY", {{"Qubit", "Qubit"}}},
        {"DPZ", {{"Qubit", "Qubit"}}},
        {"DID", {{"Qubit", "Qubit"}}},
        {"DTOF", {{"Qubit", "Qubit"}, {"Qubit", "Qubit"}}},
        {"DRX", {{"Qubit", "Qubit"}}},
        {"DRY", {{"Qubit", "Qubit"}}},
        {"DRZ", {{"Qubit", "Qubit"}}},
        {"DS", {{"Qubit", "Qubit"}}},
        {"DT", {{"Qubit", "Qubit"}}},
        {"DSDG", {{"Qubit", "Qubit"}}},
        {"DTDG", {{"Qubit", "Qubit"}}},
        {"DCY", {{"Qubit", "Qubit"}}},
        {"DSWP", {{"Qubit", "Qubit"}, {"Qubit", "Qubit"}}},
        {"DMES", {{"Qubit", "Qubit"}}},
        {"DCRK", {{"Qubit", "Qubit"}}},
        {"DGET", {{"Qubit", "Qubit"}}},
    };
