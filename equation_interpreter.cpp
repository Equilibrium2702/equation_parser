#include "equation_interpreter.h"
#include <string>

EquationInterpreter::EquationInterpreter(std::string expression)
{
  calculator_ast<str_t_it> calc;

  str_t_it begin = expression.begin(), end = expression.end();

  bool success = qi::phrase_parse( begin, end, calc, qi::space, ast);
  if(!(success && begin == end))
    throw std::logic_error("Parsing failed: stopped at: \""
                           + str_t(begin, end) + "\"");
}

double EquationInterpreter::solve(const std::map<char, double> &vars)
{
  return boost::apply_visitor(ast_result_calculator(2.1), ast);
}