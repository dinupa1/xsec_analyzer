# source setup_stv.sh

PROCESSED_NTUPLE_DIR="/exp/uboone/app/users/dinupa/xsec_analyzer/data"
UNIV_OUTPUT_FILE=${PROCESSED_NTUPLE_DIR}"/Universes.root"

MEASUREMENT_OUTPUT_FILE="./Output/"
UNF_MEAS_OUTPUT_FILE=${MEASUREMENT_OUTPUT_FILE}"/UnfoldedCrossSection.root"

SEL_NAMES="NC1p"

PELEE_NTUPLE_CONFIG="./configs/files_to_process_NC1p.txt"
FPM_CONFIG="./configs/file_properties_NC1p.txt"
BIN_CONFIG="./configs/nc1p_bin_config.txt"
XSEC_CONFIG="./configs/xsec_config.txt"
SLICE_CONFIG="./configs/nc1p_slice_config.txt"
SYST_CONFIG="./configs/systcalc.conf"

#./scripts/ReprocessNTuples.sh ${PROCESSED_NTUPLE_DIR} ${SEL_NAMES} ${PELEE_NTUPLE_CONFIG}
./scripts/UniverseMaker.sh ${FPM_CONFIG} ${BIN_CONFIG} ${UNIV_OUTPUT_FILE}
# ./scripts/PlotSlices.sh ${FPM_CONFIG} ${SYST_CONFIG} ${SLICE_CONFIG} ${UNIV_OUTPUT_FILE} ${MEASUREMENT_OUTPUT_FILE}
# ./scripts/Unfolder.sh ${XSEC_CONFIG} ${SLICE_CONFIG} ${UNF_MEAS_OUTPUT_FILE}
