#include "cwrapatc3dg.h"

int main() {


	int ret = 0;

	std::cout << "setResetOnInit: ";
	ret = setResetOnInit(1);
	std::cout << ret << std::endl;


	std::cout << "\ninitializeAscension: ";
	ret = initializeAscension();
	std::cout << ret << std::endl;

	
	std::cout << "\ngetSystemConfig: ";
	double measureRate = 0;
	double powerFreq = 0;
	double maxRange = 0;
	int agcMode = -1;
	int numBoards = -1;
	int numSensors = -1;
	int numTransmitters = -1;
	int runningTransmitterNum = -3;
	bool metricYN = false;
	ret = getSystemCfg(&measureRate, &powerFreq, &maxRange, &agcMode, &numBoards, &numSensors, &numTransmitters,
		&runningTransmitterNum, &metricYN);
	printf("ret{%d} rate{%3.4f}[Hz] pFreq{%3.4f}[Hz] range{%3.4f}[in|mm] agc{%d} boards{%d} sensors{%d} trans{%d} running{%d} metric{%d}\n",
		    ret, measureRate, powerFreq, maxRange, agcMode, numBoards, numSensors, numTransmitters, runningTransmitterNum, metricYN);


	ret = setMetric(1);
	printf("\nsetMetric(1): ret{%d}\n", ret);


	std::cout << "\ngetAngleAlign(0): ";
	double angleAER[3] = { 0, 0, 0 };
	ret = getAngleAlign(0, angleAER);
	printf("ret{%d} A{%3.4f} E{%3.4f} R{%3.4f}\n", ret, angleAER[0], angleAER[1], angleAER[2]);

	//std::cout << "setAngleAlign(0): ";
	//angleAER[0] = 0.1;
	//angleAER[1] = 0.2;
	//angleAER[2] = 0.3;
	//ret = setAngleAlign(0, angleAER);
	//std::cout << ret << std::endl;

	std::cout << "getAngleAlign(0): ";
	ret = getAngleAlign(0, angleAER);
	printf("ret{%d} A{%3.4f} E{%3.4f} R{%3.4f}\n", ret, angleAER[0], angleAER[1], angleAER[2]);

	std::cout << "getAngleAlign(1): ";
	ret = getAngleAlign(1, angleAER);
	printf("ret{%d} A{%3.4f} E{%3.4f} R{%3.4f}\n", ret, angleAER[0], angleAER[1], angleAER[2]);

	//std::cout << "setAngleAlign(1): ";
	//angleAER[0] = 0.1;
	//angleAER[1] = 0.2;
	//angleAER[2] = 0.3;
	//ret = setAngleAlign(1, angleAER);
	//std::cout << ret << std::endl;

	std::cout << "getAngleAlign(1): ";
	ret = getAngleAlign(1, angleAER);
	printf("ret{%d} A{%3.4f} E{%3.4f} R{%3.4f}\n", ret, angleAER[0], angleAER[1], angleAER[2]);

	//std::cout << "setAngleAlign(0&1) to 0s: ";
	//angleAER[0] = 0.;
	//angleAER[1] = 0.;
	//angleAER[2] = 0.;
	//ret = setAngleAlign(0, angleAER);
	//std::cout << ret << " ";
	//ret = setAngleAlign(1, angleAER);
	//std::cout << ret << std::endl;

	
	printf("\nsetTxAngleAlign:\n");
	double transmitterANG[3] = { 0.1,0.2,0.3 };
	int transmitterXYZOn = 0;
	ret = setTxReferenceFrame(0, transmitterANG, &transmitterXYZOn);

	std::cout << "\ngetTxReferenceFrame: ";
	ret = getTxReferenceFrame(0, transmitterANG, &transmitterXYZOn);
	printf("ret{%d} ang = [%3.4f, %3.4f, %3.4f]; on{%d}\n", ret, transmitterANG[0], transmitterANG[1], transmitterANG[2], transmitterXYZOn);


	std::cout << "\ngetSensorOffset(0): ";
	double pos[3] = { -1,-1,-1 };
	ret = getSensorOffset(0, pos);
	printf("ret{%d} x{%3.4f} y{%3.4f} z{%3.4f}\n", ret, pos[0], pos[1], pos[2]);
	std::cout << "getSensorOffset(1): ";
	ret = getSensorOffset(1, pos);
	printf("ret{%d} x{%3.4f} y{%3.4f} z{%3.4f}\n", ret, pos[0], pos[1], pos[2]);


	std::cout << "\ngetHemisphere: ";
	int hemi = -1;
	ret = getHemisphere(0, &hemi);
	printf("s0: ret{%d} hemi{%d} ", ret, hemi);
	ret = getHemisphere(1, &hemi);
	printf("s1: ret{%d} hemi{%d}\n", ret, hemi);


	std::cout << "\ngetACWide: ";
	int acOnOff = -1;
	ret = getFilterACWideNotch(0, &acOnOff);
	printf("s0: ret{%d} ACWide{%d} ", ret, acOnOff);
	ret = getFilterACWideNotch(1, &acOnOff);
	printf("s1: ret{%d} ACWide{%d}\n", ret, acOnOff);

	std::cout << "\nsetACWide: ";
	acOnOff = 0;
	ret = setFilterACWideNotch(0, &acOnOff);
	printf("s0: ret{%d} ", ret);
	ret = setFilterACWideNotch(1, &acOnOff);
	printf("s1: ret{%d} ", ret);
	ret = getFilterACWideNotch(0, &acOnOff);
	printf("s0: ret{%d} ACWide{%d} ", ret, acOnOff);
	ret = getFilterACWideNotch(1, &acOnOff);
	printf("s1: ret{%d} ACWide{%d}\n", ret, acOnOff);


	std::cout << "\ngetACNarrow: ";
	//int acOnOff = -1;
	ret = getFilterACNarrowNotch(0, &acOnOff);
	printf("s0: ret{%d} ACNarrow{%d} ", ret, acOnOff);
	ret = getFilterACNarrowNotch(1, &acOnOff);
	printf("s1: ret{%d} ACNarrow{%d}\n", ret, acOnOff);

	std::cout << "\nsetACNarrow: ";
	//int acOnOff = -1;
	acOnOff = 0;
	ret = setFilterACNarrowNotch(0, &acOnOff);
	printf("s0: ret{%d} ", ret);
	ret = setFilterACNarrowNotch(1, &acOnOff);
	printf("s1: ret{%d} ", ret);
	ret = getFilterACNarrowNotch(0, &acOnOff);
	printf("s0: ret{%d} ACNarrow{%d} ", ret, acOnOff);
	ret = getFilterACNarrowNotch(1, &acOnOff);
	printf("s1: ret{%d} ACNarrow{%d}\n", ret, acOnOff);


	std::cout << "\ngetDCAdaptive: ";
	double dcAdapt = -1.1;
	ret = getFilterDCAdaptive(0, &dcAdapt);
	printf("s0: ret{%d} DCAdapt{%f} ", ret, dcAdapt);
	ret = getFilterDCAdaptive(1, &dcAdapt);
	printf("s1: ret{%d} DCAdapt{%f}\n", ret, dcAdapt);

	std::cout << "\nsetDCAdaptive: ";
	dcAdapt = 0;
	ret = setFilterDCAdaptive(0, &dcAdapt);
	printf("s0: ret{%d} ", ret);
	ret = setFilterDCAdaptive(1, &dcAdapt);
	printf("s1: ret{%d} ", ret);
	ret = getFilterDCAdaptive(0, &dcAdapt);
	printf("s0: ret{%d} DCAdapt{%f} ", ret, dcAdapt);
	ret = getFilterDCAdaptive(1, &dcAdapt);
	printf("s1: ret{%d} DCAdapt{%f}\n", ret, dcAdapt);

	std::cout << "\ngetAlpha:\n";
	int aMax[7], aMin[7], noiseVm[7], alphaOn;
	ret = getFilterAlphaAdaptive(0, aMax, aMin, noiseVm, &alphaOn);
	printf("s0: ret{%d} aMax{%d %d %d %d %d %d %d} aMin{%d %d %d %d %d %d %d} vm{%d %d %d %d %d %d %d} on{%d}\n",
		ret, aMax[0], aMax[1], aMax[2], aMax[3], aMax[4], aMax[5], aMax[6], aMin[0], aMin[1], aMin[2], aMin[3], aMin[4], aMin[5], aMax[6],
		noiseVm[0], noiseVm[1], noiseVm[2], noiseVm[3], noiseVm[4], noiseVm[5], noiseVm[6], alphaOn);
	ret = getFilterAlphaAdaptive(1, aMax, aMin, noiseVm, &alphaOn);
	printf("s0: ret{%d} aMax{%d %d %d %d %d %d %d} aMin{%d %d %d %d %d %d %d} vm{%d %d %d %d %d %d %d} on{%d}\n",
		ret, aMax[0], aMax[1], aMax[2], aMax[3], aMax[4], aMax[5], aMax[6], aMin[0], aMin[1], aMin[2], aMin[3], aMin[4], aMin[5], aMax[6],
		noiseVm[0], noiseVm[1], noiseVm[2], noiseVm[3], noiseVm[4], noiseVm[5], noiseVm[6], alphaOn);


	printf("\ngetAsynchronousSensorPositionAngles:\n");
	int recordType = 12; //posAngles
	double ang[3];
	ret = setSensorDataFormat(0, recordType);
	ret = setSensorDataFormat(1, recordType);
	ret = setSensorDataFormat(2, recordType);
	ret = setSelectedTransmitter(0);
	ret = getAsynchronousSensorPositionAngles(0, pos, ang);
	printf("xyz = [%3.4f %3.4f %3.4f]; ang = [%3.4f %3.4f %3.4f];\n", pos[0], pos[1], pos[2], ang[0], ang[1], ang[2]);
	ret = getAsynchronousSensorPositionAngles(1, pos, ang);
	printf("xyz = [%3.4f %3.4f %3.4f]; ang = [%3.4f %3.4f %3.4f];\n", pos[0], pos[1], pos[2], ang[0], ang[1], ang[2]);
	ret = getAsynchronousSensorPositionAngles(2, pos, ang);
	printf("xyz = [%3.4f %3.4f %3.4f]; ang = [%3.4f %3.4f %3.4f];\n", pos[0], pos[1], pos[2], ang[0], ang[1], ang[2]);
	ret = setSelectedTransmitter(-1);

	printf("\ngetAsynchronousSensorPositionMatrix:\n");
	recordType = 13; //posMat
	double rmx[9];
	ret = setSensorDataFormat(0, recordType);
	ret = setSensorDataFormat(1, recordType);
	ret = setSensorDataFormat(2, recordType);
	ret = setSelectedTransmitter(0);
	ret = getAsynchronousSensorPositionMatrix(0, pos, rmx);
	printf("xyz = [%3.4f %3.4f %3.4f]; rmx =[%3.4f %3.4f %3.4f %3.4f %3.4f %3.4f %3.4f %3.4f %3.4f];\n", pos[0], pos[1], pos[2], rmx[0], rmx[1], rmx[2], rmx[3], rmx[4], rmx[5], rmx[6], rmx[7], rmx[8]);
	ret = getAsynchronousSensorPositionMatrix(1, pos, rmx);
	printf("xyz = [%3.4f %3.4f %3.4f]; rmx =[%3.4f %3.4f %3.4f %3.4f %3.4f %3.4f %3.4f %3.4f %3.4f];\n", pos[0], pos[1], pos[2], rmx[0], rmx[1], rmx[2], rmx[3], rmx[4], rmx[5], rmx[6], rmx[7], rmx[8]);
	ret = getAsynchronousSensorPositionMatrix(2, pos, rmx);
	printf("xyz = [%3.4f %3.4f %3.4f]; rmx =[%3.4f %3.4f %3.4f %3.4f %3.4f %3.4f %3.4f %3.4f %3.4f];\n", pos[0], pos[1], pos[2], rmx[0], rmx[1], rmx[2], rmx[3], rmx[4], rmx[5], rmx[6], rmx[7], rmx[8]);
	ret = setSelectedTransmitter(-1);

	std::cout << "\ngetAsynchronousSensorPositionQuaternion:\n";
	recordType = 14; //posQuat
	ret = setSensorDataFormat(0, recordType);
	ret = setSensorDataFormat(1, recordType);
	ret = setSensorDataFormat(2, recordType);
	ret = setSelectedTransmitter(0);
	double quat[4] = { 0,0,0,0 };
	ret = getAsynchronousSensorPositionQuaternion(0, pos, quat);
	printf("xyz = [%3.4f %3.4f %3.4f]; quat = [%3.4f %3.4f %3.4f %3.4f];\n", pos[0], pos[1], pos[2], quat[0], quat[1], quat[2], quat[3]);
	ret = getAsynchronousSensorPositionQuaternion(1, pos, quat);
	printf("xyz = [%3.4f %3.4f %3.4f]; quat = [%3.4f %3.4f %3.4f %3.4f];\n", pos[0], pos[1], pos[2], quat[0], quat[1], quat[2], quat[3]);
	ret = getAsynchronousSensorPositionQuaternion(2, pos, quat);
	printf("xyz = [%3.4f %3.4f %3.4f]; quat = [%3.4f %3.4f %3.4f %3.4f];\n", pos[0], pos[1], pos[2], quat[0], quat[1], quat[2], quat[3]);
	ret = setSelectedTransmitter(-1);


	ret = setSelectedTransmitter(0);
	printf("\ngetAsynchronousAllSensorPositionQuaternion:\n");
	recordType = 14; //posQuat
	ret = setSensorDataFormat(0, recordType);
	ret = setSensorDataFormat(1, recordType);
	ret = setSensorDataFormat(2, recordType);
	ret = setSensorDataFormat(3, recordType);
	printf("set3: ret %d\n", ret);
	double pos0[3], pos1[3], pos2[3], pos3[3];
	double quat0[4], quat1[4], quat2[4], quat3[4];
	ret = getAsynchronousAllSensorsPositionQuaternion(pos0, quat0, pos1, quat1, pos2, quat2, pos3, quat3);
	printf("xyz0 = [%3.4f %3.4f %3.4f]; quat0 = [%3.4f %3.4f %3.4f %3.4f]\n", pos0[0], pos0[1], pos0[2], quat0[0], quat0[1], quat0[2], quat0[3]);
	printf("xyz1 = [%3.4f %3.4f %3.4f]; quat1 = [%3.4f %3.4f %3.4f %3.4f]\n", pos1[0], pos1[1], pos1[2], quat1[0], quat1[1], quat1[2], quat1[3]);
	printf("xyz2 = [%3.4f %3.4f %3.4f]; quat2 = [%3.4f %3.4f %3.4f %3.4f]\n", pos2[0], pos2[1], pos2[2], quat2[0], quat2[1], quat2[2], quat2[3]);
	printf("xyz3 = [%3.4f %3.4f %3.4f]; quat3 = [%3.4f %3.4f %3.4f %3.4f]\n", pos3[0], pos3[1], pos3[2], quat3[0], quat3[1], quat3[2], quat3[3]);

	printf("\ngetSynchronousSensorPositionQuaternion:\n");
	ret = getSynchronousSensorPositionQuaternion(0, pos0, quat0);
	ret = getSynchronousSensorPositionQuaternion(0, pos1, quat1);
	ret = getSynchronousSensorPositionQuaternion(0, pos2, quat2);
	ret = getSynchronousSensorPositionQuaternion(0, pos3, quat3);
	printf("xyz0 = [%3.4f %3.4f %3.4f]; quat0 = [%3.4f %3.4f %3.4f %3.4f]\n", pos0[0], pos0[1], pos0[2], quat0[0], quat0[1], quat0[2], quat0[3]);
	printf("xyz1 = [%3.4f %3.4f %3.4f]; quat1 = [%3.4f %3.4f %3.4f %3.4f]\n", pos1[0], pos1[1], pos1[2], quat1[0], quat1[1], quat1[2], quat1[3]);
	printf("xyz2 = [%3.4f %3.4f %3.4f]; quat2 = [%3.4f %3.4f %3.4f %3.4f]\n", pos2[0], pos2[1], pos2[2], quat2[0], quat2[1], quat2[2], quat2[3]);
	printf("xyz3 = [%3.4f %3.4f %3.4f]; quat3 = [%3.4f %3.4f %3.4f %3.4f]\n", pos3[0], pos3[1], pos3[2], quat3[0], quat3[1], quat3[2], quat3[3]);

	printf("\ngetSynchronusAllSensorsPositionQuaternion:\n");
	ret = getSynchronousAllSensorsPositionQuaternion(pos0, quat0, pos1, quat1, pos2, quat2, pos3, quat3);
	printf("xyz0 = [%3.4f %3.4f %3.4f]; quat0 = [%3.4f %3.4f %3.4f %3.4f]\n", pos0[0], pos0[1], pos0[2], quat0[0], quat0[1], quat0[2], quat0[3]);
	printf("xyz1 = [%3.4f %3.4f %3.4f]; quat1 = [%3.4f %3.4f %3.4f %3.4f]\n", pos1[0], pos1[1], pos1[2], quat1[0], quat1[1], quat1[2], quat1[3]);
	printf("xyz2 = [%3.4f %3.4f %3.4f]; quat2 = [%3.4f %3.4f %3.4f %3.4f]\n", pos2[0], pos2[1], pos2[2], quat2[0], quat2[1], quat2[2], quat2[3]);
	printf("xyz3 = [%3.4f %3.4f %3.4f]; quat3 = [%3.4f %3.4f %3.4f %3.4f]\n", pos3[0], pos3[1], pos3[2], quat3[0], quat3[1], quat3[2], quat3[3]);
	ret = getSynchronousAllSensorsPositionQuaternion(pos0, quat0, pos1, quat1, pos2, quat2, pos3, quat3);
	printf("xyz0 = [%3.4f %3.4f %3.4f]; quat0 = [%3.4f %3.4f %3.4f %3.4f]\n", pos0[0], pos0[1], pos0[2], quat0[0], quat0[1], quat0[2], quat0[3]);
	printf("xyz1 = [%3.4f %3.4f %3.4f]; quat1 = [%3.4f %3.4f %3.4f %3.4f]\n", pos1[0], pos1[1], pos1[2], quat1[0], quat1[1], quat1[2], quat1[3]);
	printf("xyz2 = [%3.4f %3.4f %3.4f]; quat2 = [%3.4f %3.4f %3.4f %3.4f]\n", pos2[0], pos2[1], pos2[2], quat2[0], quat2[1], quat2[2], quat2[3]);
	printf("xyz3 = [%3.4f %3.4f %3.4f]; quat3 = [%3.4f %3.4f %3.4f %3.4f]\n", pos3[0], pos3[1], pos3[2], quat3[0], quat3[1], quat3[2], quat3[3]);
	ret = getSynchronousAllSensorsPositionQuaternion(pos0, quat0, pos1, quat1, pos2, quat2, pos3, quat3);
	printf("xyz0 = [%3.4f %3.4f %3.4f]; quat0 = [%3.4f %3.4f %3.4f %3.4f]\n", pos0[0], pos0[1], pos0[2], quat0[0], quat0[1], quat0[2], quat0[3]);
	printf("xyz1 = [%3.4f %3.4f %3.4f]; quat1 = [%3.4f %3.4f %3.4f %3.4f]\n", pos1[0], pos1[1], pos1[2], quat1[0], quat1[1], quat1[2], quat1[3]);
	printf("xyz2 = [%3.4f %3.4f %3.4f]; quat2 = [%3.4f %3.4f %3.4f %3.4f]\n", pos2[0], pos2[1], pos2[2], quat2[0], quat2[1], quat2[2], quat2[3]);
	printf("xyz3 = [%3.4f %3.4f %3.4f]; quat3 = [%3.4f %3.4f %3.4f %3.4f]\n", pos3[0], pos3[1], pos3[2], quat3[0], quat3[1], quat3[2], quat3[3]);
	
	ret = setSelectedTransmitter(-1);

	std::getchar();
	return 0;
}
