
// XSecAnalyzer includes
#include "XSecAnalyzer/Selections/NC1p.hh"
#include "XSecAnalyzer/Selections/DummySelection.hh"
#include "XSecAnalyzer/Selections/SelectionFactory.hh"

SelectionFactory::SelectionFactory() {
}

SelectionBase* SelectionFactory::CreateSelection(
  const std::string& selection_name )
{
  SelectionBase* sel;
  if ( selection_name == "NC1p" ) {
    sel = new NC1p;
  }
  else if ( selection_name == "Dummy" ) {
    sel = new DummySelection;
  }
  else {
    std::cerr << "Selection name requested: " << selection_name
      << " is not implemented in " << __FILE__ << '\n';
    throw;
  }

  // Ensure that the owned map of category definitions is set up
  sel->define_category_map();

  return sel;
}
