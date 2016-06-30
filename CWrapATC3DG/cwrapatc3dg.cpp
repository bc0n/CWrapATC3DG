#include "cwrapatc3dg.h"

//DLLIMPORT watc* createCWrapATC3DG(void)


DLLIMPORT int initializeAscension() {
	int errorCode = -1;

	errorCode = InitializeBIRDSystem();

	return errorCode;
}


//Getters GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG
DLLIMPORT int getSystemCfg(double *measureRate, double *powerFreq, double *maxRange,
	int *agcMode, int *numBoards, int *numSensors, int *numTransmitters,
	int *runningTransmitterNum, bool *metricYN) {

	int errorCode = -1;
	SYSTEM_CONFIGURATION sysCfg;
	
	errorCode = GetBIRDSystemConfiguration(&sysCfg);

	*measureRate = sysCfg.measurementRate;
	*powerFreq = sysCfg.powerLineFrequency;
	*maxRange = sysCfg.maximumRange;
	*agcMode = sysCfg.agcMode;
	*numBoards = sysCfg.numberBoards;
	*numSensors = sysCfg.numberSensors;
	*numTransmitters = sysCfg.numberTransmitters;
	*runningTransmitterNum = sysCfg.transmitterIDRunning;
	*metricYN = sysCfg.metric == TRUE;  //.metric is a BOOL, metric is a bool

	return errorCode;
}

DLLIMPORT int getAsynchronousSensorPositionAngles(int sensorNum, double *pos, double *ang) {
	int errorCode = -1;

	DOUBLE_POSITION_ANGLES_RECORD record, *precord = &record;

	errorCode = GetAsynchronousRecord(sensorNum, precord, sizeof(record));

	pos[0] = record.x;
	pos[1] = record.y;
	pos[2] = record.z;

	ang[0] = record.a*M_DEG2RAD;
	ang[1] = record.e*M_DEG2RAD;
	ang[2] = record.r*M_DEG2RAD;

	return errorCode;
}

DLLIMPORT int getAsynchronousSensorPositionMatrix(int sensorNum, double *pos, double *rmx) {
	int errorCode = -1;
	
	DOUBLE_POSITION_MATRIX_RECORD record, *precord = &record;

	errorCode = GetAsynchronousRecord(sensorNum, precord, sizeof(record));

	pos[0] = record.x;
	pos[1] = record.y;
	pos[2] = record.z;

	rmx[0] = record.s[0][0]; //R11
	rmx[1] = record.s[1][0]; //R21
	rmx[2] = record.s[2][0]; //R31
	rmx[3] = record.s[0][1]; //R12
	rmx[4] = record.s[1][1]; //R22
	rmx[5] = record.s[2][1]; //R32
	rmx[6] = record.s[0][2]; //R13
	rmx[7] = record.s[1][2]; //R23
	rmx[8] = record.s[2][2]; //R33

	return errorCode;
}

DLLIMPORT int getAsynchronousSensorPositionQuaternion(int sensorNum, double *pos, double *quat) {
	int errorCode = -1;

	DOUBLE_POSITION_QUATERNION_RECORD record, *precord = &record;

	errorCode = GetAsynchronousRecord(sensorNum, precord, sizeof(record));

	pos[0] = record.x;
	pos[1] = record.y;
	pos[2] = record.z;

	quat[0] = record.q[0]; //use a copy-thing here?
	quat[1] = record.q[1];
	quat[2] = record.q[2];
	quat[3] = record.q[3];

	return errorCode;
}

DLLIMPORT int getAsynchronousAllSensorsPositionQuaternion( double *pos0, double *quat0, double *pos1, double *quat1, double *pos2, double *quat2, double *pos3, double *quat3) {
	int errorCode = -1;

	DOUBLE_POSITION_QUATERNION_RECORD record[4];

	errorCode = GetAsynchronousRecord(ALL_SENSORS, record, 4 * sizeof(record[0]));
	//printf("ret %d\n", errorCode);
	//printf("xyz0 = [%3.4f %3.4f %3.4f]\n", record[0].x,record[0].y,record[0].z);
	pos0[0]= record[0].x;
	pos0[1] = record[0].y;
	pos0[2] = record[0].z;
	quat0[0] = record[0].q[0];
	quat0[1] = record[0].q[1];
	quat0[2] = record[0].q[2];
	quat0[3] = record[0].q[3];
	pos1[0] = record[1].x;
	pos1[1] = record[1].y;
	pos1[2] = record[1].z;
	quat1[0] = record[1].q[0];
	quat1[1] = record[1].q[1];
	quat1[2] = record[1].q[2];
	quat1[3] = record[1].q[3];
	pos2[0] = record[2].x;
	pos2[1] = record[2].y;
	pos2[2] = record[2].z;
	quat2[0] = record[2].q[0];
	quat2[1] = record[2].q[1];
	quat2[2] = record[2].q[2];
	quat2[3] = record[2].q[3];
	pos3[0] = record[3].x;
	pos3[1] = record[3].y;
	pos3[2] = record[3].z;
	quat3[0] = record[3].q[0];
	quat3[1] = record[3].q[1];
	quat3[2] = record[3].q[2];
	quat3[3] = record[3].q[3];

	return errorCode;
}

DLLIMPORT int getSynchronousSensorPositionQuaternion(int sensorNum, double *pos, double *quat) {
	int errorCode = -1;

	DOUBLE_POSITION_QUATERNION_RECORD record, *precord = &record;

	errorCode = GetSynchronousRecord(sensorNum, precord, sizeof(record));

	pos[0] = record.x;
	pos[1] = record.y;
	pos[2] = record.z;

	quat[0] = record.q[0];
	quat[1] = record.q[1];
	quat[2] = record.q[2];
	quat[3] = record.q[3];

	return errorCode;
}

DLLIMPORT int getSynchronousAllSensorsPositionQuaternion(double *pos0, double *quat0, double *pos1, double *quat1, double *pos2, double *quat2, double *pos3, double *quat3) {
	int errorCode = -1;

	DOUBLE_POSITION_QUATERNION_RECORD record[4];

	errorCode = GetSynchronousRecord(ALL_SENSORS, record, 4 * sizeof(record[0]));
	pos0[0] = record[0].x;
	pos0[1] = record[0].y;
	pos0[2] = record[0].z;
	quat0[0] = record[0].q[0];
	quat0[1] = record[0].q[1];
	quat0[2] = record[0].q[2];
	quat0[3] = record[0].q[3];
	pos1[0] = record[1].x;
	pos1[1] = record[1].y;
	pos1[2] = record[1].z;
	quat1[0] = record[1].q[0];
	quat1[1] = record[1].q[1];
	quat1[2] = record[1].q[2];
	quat1[3] = record[1].q[3];
	pos2[0] = record[2].x;
	pos2[1] = record[2].y;
	pos2[2] = record[2].z;
	quat2[0] = record[2].q[0];
	quat2[1] = record[2].q[1];
	quat2[2] = record[2].q[2];
	quat2[3] = record[2].q[3];
	pos3[0] = record[3].x;
	pos3[1] = record[3].y;
	pos3[2] = record[3].z;
	quat3[0] = record[3].q[0];
	quat3[1] = record[3].q[1];
	quat3[2] = record[3].q[2];
	quat3[3] = record[3].q[3];

	return errorCode;
}

// GetSensorParameter expanded:
DLLIMPORT int getSensorDataFormat(int sensorNum, int *dataRecordType) {
	int errorCode = -1;

	DATA_FORMAT_TYPE buffer;
	DATA_FORMAT_TYPE *pbuffer = &buffer;
	*dataRecordType = buffer;
	errorCode = GetSensorParameter((short)sensorNum, DATA_FORMAT, pbuffer, sizeof(buffer));

	return errorCode;
}

DLLIMPORT int getAngleAlign(int sensorNum, double *angleAER) {
	int errorCode = -1;

	DOUBLE_ANGLES_RECORD buffer; // record is degrees
	DOUBLE_ANGLES_RECORD *pbuffer = &buffer;
	errorCode = GetSensorParameter((short)sensorNum, ANGLE_ALIGN, pbuffer, sizeof(buffer));
	
	angleAER[0] = buffer.a * M_DEG2RAD;
	angleAER[1] = buffer.e * M_DEG2RAD;
	angleAER[2] = buffer.r * M_DEG2RAD;

	return errorCode;
}

DLLIMPORT int getSensorOffset(int sensorNum, double *posOffset) {
	int errorCode = -1;

	DOUBLE_POSITION_RECORD buffer;
	DOUBLE_POSITION_RECORD *pbuffer = &buffer;
	errorCode = GetSensorParameter((short)sensorNum, SENSOR_OFFSET, pbuffer, sizeof(buffer));

	posOffset[0] = buffer.x;
	posOffset[1] = buffer.y;
	posOffset[2] = buffer.z;

	return errorCode;
}

DLLIMPORT int getHemisphere(int sensorNum, int *hemisphereType) {
	int errorCode = -1;

	HEMISPHERE_TYPE buffer;
	HEMISPHERE_TYPE *pbuffer = &buffer;
	errorCode = GetSensorParameter((short)sensorNum, HEMISPHERE, pbuffer, sizeof(buffer));

	*hemisphereType = buffer;

	return errorCode;
}

DLLIMPORT int getFilterACWideNotch(int sensorNum, int *filterOnOff) {
	int errorCode = -1;

	errorCode = GetSensorParameter((short)sensorNum, FILTER_AC_WIDE_NOTCH, &(*filterOnOff), sizeof(int));

	return errorCode;
}

DLLIMPORT int getFilterACNarrowNotch(int sensorNum, int *filterOnOff) {
	int errorCode = -1;

	//BOOL buffer, *pBuffer = &buffer;
	int buffer, *pBuffer = &buffer;
	//errorCode = GetSensorParameter((short)sensorNum, FILTER_AC_NARROW_NOTCH, pBuffer, sizeof(int));
	//printf("getFilterACNarrow &%d *%d %d\n", &pBuffer, *pBuffer, pBuffer);
	//*filterOnOff = buffer;
	errorCode = GetSensorParameter((short)sensorNum, FILTER_AC_NARROW_NOTCH, &(*filterOnOff), sizeof(int));
	//printf("\ngetFilterACNarrow *%d %d\n", *filterOnOff, filterOnOff);
	return errorCode;
}

DLLIMPORT int getFilterDCAdaptive(int sensorNum, double *value) {
	int errorCode = -1;
	errorCode = GetSensorParameter((short) sensorNum, FILTER_DC_ADAPTIVE, value, sizeof(double));

	return errorCode;
}

DLLIMPORT int getFilterAlphaAdaptive(int sensorNum, int *alphaMax, int *alphaMin, int *noiseVm, int *alphaOn) {
	int errorCode = -1;

	ADAPTIVE_PARAMETERS buffer, *pBuffer = &buffer;
	errorCode = GetSensorParameter((short)sensorNum, FILTER_ALPHA_PARAMETERS, pBuffer, sizeof(buffer));

	alphaMax[0] = (int)buffer.alphaMax[0];
	alphaMax[1] = (int)buffer.alphaMax[1];
	alphaMax[2] = (int)buffer.alphaMax[2];
	alphaMax[3] = (int)buffer.alphaMax[3];
	alphaMax[4] = (int)buffer.alphaMax[4];
	alphaMax[5] = (int)buffer.alphaMax[5];
	alphaMax[6] = (int)buffer.alphaMax[6];
	alphaMin[0] = (int)buffer.alphaMin[0];
	alphaMin[1] = (int)buffer.alphaMin[1];
	alphaMin[2] = (int)buffer.alphaMin[2];
	alphaMin[3] = (int)buffer.alphaMin[3];
	alphaMin[4] = (int)buffer.alphaMin[4];
	alphaMin[5] = (int)buffer.alphaMin[5];
	alphaMin[6] = (int)buffer.alphaMin[6];
	noiseVm[0] = (int)buffer.vm[0];
	noiseVm[1] = (int)buffer.vm[1];
	noiseVm[2] = (int)buffer.vm[2];
	noiseVm[3] = (int)buffer.vm[3];
	noiseVm[4] = (int)buffer.vm[4];
	noiseVm[5] = (int)buffer.vm[5];
	noiseVm[6] = (int)buffer.vm[6];
	*alphaOn = (int)buffer.alphaOn;

	return errorCode;
}

DLLIMPORT int getFilterLargeChange(int sensorNum, int *filterOnOff) {
	int errorCode = -1;

	BOOL buffer, *pBuffer = &buffer;
	errorCode = GetSensorParameter((short)sensorNum, FILTER_LARGE_CHANGE, pBuffer, sizeof(buffer));

	return errorCode;
}

DLLIMPORT int getQuality(int sensorNum, int *errorOffset, int *errorSensitivity, int *errorSlope, int *filterAlpha) {
	int errorCode = -1;

	QUALITY_PARAMETERS buffer, *pBuffer = &buffer;
	errorCode = GetSensorParameter((short)sensorNum, QUALITY, pBuffer, sizeof(buffer));
	*errorOffset = (int)buffer.error_offset;
	*errorSensitivity = (int)buffer.error_sensitivity;
	*errorSlope = (int)buffer.error_slope;
	*filterAlpha = (int)buffer.filter_alpha;
	
	return errorCode;
}

// GetTransmitterParameter expanded:
DLLIMPORT int getTxReferenceFrame(int transmitterNum, double *transmitterAER, int *transmitterXYZOn) {
	int errorCode = -1;

	DOUBLE_ANGLES_RECORD aer, *paer = &aer;
	errorCode = GetTransmitterParameter((short) transmitterNum, REFERENCE_FRAME, paer, sizeof(aer));

	BOOL buffer = FALSE, *pBuffer = &buffer;
	if (errorCode == BIRD_ERROR_SUCCESS) {
		errorCode = GetTransmitterParameter((short)transmitterNum, XYZ_REFERENCE_FRAME, pBuffer, sizeof(buffer));
	}

	transmitterAER[0] = aer.a * M_DEG2RAD;
	transmitterAER[1] = aer.e * M_DEG2RAD;
	transmitterAER[2] = aer.r * M_DEG2RAD;
	*transmitterXYZOn = (int)(buffer==TRUE);

	return errorCode;
}


//Setters SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS
// SetSystemParameter expanded:
DLLIMPORT int setSelectedTransmitter(int transmitterNum) {
	int errorCode = -1;

	//errorCode = SetSystemParameter(SELECT_TRANSMITTER, &transmitterNum, sizeof(transmitterNum));

	//short buffer = 0; //(short) transmitterNum;
	//short *pbuffer = &buffer;
	//errorCode = SetSystemParameter(SELECT_TRANSMITTER, pbuffer, sizeof(buffer));

	short buffer = 0;			// select transmitter ID = 0 (the 1st transmitter)
	short *pBuffer = &buffer;
	errorCode = SetSystemParameter(SELECT_TRANSMITTER, pBuffer, sizeof(buffer));


	return errorCode;
}

//DLLIMPORT int setPowerLineFrequency(int setTo50)

DLLIMPORT int setAutoGainMode(int autoTransGainOn) {
	int errorCode = -1;
	AGC_MODE_TYPE buffer = TRANSMITTER_AND_SENSOR_AGC;
	if (autoTransGainOn == 0) {
		AGC_MODE_TYPE buffer = SENSOR_AGC_ONLY;
	}
	
	AGC_MODE_TYPE *pBuffer = &buffer;
	printf("AGC_MODE: %d\n", buffer);
	errorCode = SetSystemParameter(AGC_MODE, pBuffer, sizeof(buffer));

	return errorCode;
}

DLLIMPORT int setMeasurementRate(double *measureRateHz) {
	int errorCode = -1;

	errorCode = SetSystemParameter(MEASUREMENT_RATE, measureRateHz, sizeof(double));

	return errorCode;
}

DLLIMPORT int setMetric(int metricOn) {
	int errorCode = -1;

	BOOL buffer = metricOn == 1;
	BOOL *pBuffer = &buffer;
	errorCode = SetSystemParameter(METRIC, pBuffer, sizeof(buffer));

	return errorCode;
}

DLLIMPORT int setResetOnInit(int resetOnOff) {
	int errorCode = -1;

	BOOL buffer = false;
	buffer = resetOnOff == 1;
	BOOL *pBuffer = &buffer;
	errorCode = SetSystemParameter(RESET, pBuffer, sizeof(buffer));

	return errorCode;
}

// SetSensorParameter expanded:
DLLIMPORT int setSensorDataFormat(int sensorNum, int dataRecordType) {
	int errorCode = -1;

	//DOUBLE_POSITION = 8;
	//DOUBLE_POSITION_ANGLES = 12;
	//DOUBLE_POSITION_MATRIX = 13;
	//DOUBLE_POSITION_QUATERNION = 14;
	
	//printf("*dataRecordType %d == (DATA_FORMAT_TYPE)*dataRecordType %d\n", *dataRecordType, (DATA_FORMAT_TYPE)*dataRecordType);

	DATA_FORMAT_TYPE buffer = (DATA_FORMAT_TYPE)dataRecordType;
	DATA_FORMAT_TYPE *pbuffer = &buffer;
	errorCode = SetSensorParameter(sensorNum, DATA_FORMAT, pbuffer, sizeof(buffer));

	return errorCode;
}

DLLIMPORT int setAngleAlign(int sensorNum, double *angleAER) { //not working
//DLLIMPORT int setAngleAlign(int sensorNum, double *angleA, double *angleE, double *angleR){
	int errorCode = -1;

	DOUBLE_ANGLES_RECORD anglesRecord = { 30, 45, 60 }; // in degrees
	anglesRecord.a = angleAER[0] / M_DEG2RAD;
	anglesRecord.e = angleAER[1] / M_DEG2RAD;
	anglesRecord.r = angleAER[2] / M_DEG2RAD;
	//anglesRecord.a = 1 / M_DEG2RAD * angleAER[0]; //works
	//anglesRecord.e = 1 / M_DEG2RAD * angleAER[1];
	//anglesRecord.r = 1 / M_DEG2RAD * angleAER[2];
	//anglesRecord.a = angleAER[0];
	//anglesRecord.e = angleAER[1];
	//anglesRecord.r = angleAER[2];
	//anglesRecord.a /= M_DEG2RAD;
	//anglesRecord.e /= M_DEG2RAD;
	//anglesRecord.r /= M_DEG2RAD;

	if (anglesRecord.a < -180.000)
		anglesRecord.a = -180.000; //from 'DOUBLE_ANGLES_RECORD' on pg 139
	if (anglesRecord.a > 179.995)
		anglesRecord.a = 179.995;
	if (anglesRecord.e < -90.000)
		anglesRecord.e = -90.000;
	if (anglesRecord.e > 89.995)
		anglesRecord.e = 89.995;
	if (anglesRecord.r < -180.000)
		anglesRecord.r = -180.000;
	if (anglesRecord.r > 179.995)
		anglesRecord.r = 179.995;

	DOUBLE_ANGLES_RECORD *panglesRecord = &anglesRecord;
	errorCode = SetSensorParameter((short)sensorNum, ANGLE_ALIGN, panglesRecord, sizeof(anglesRecord));

	return errorCode;
}

DLLIMPORT int setSensorOffset(int sensorNum, double *posOffset) {
	int errorCode = -1;

	DOUBLE_POSITION_RECORD posRecord;
	posRecord.x = posOffset[0];
	posRecord.y = posOffset[1];
	posRecord.z = posOffset[2];
	
	DOUBLE_POSITION_RECORD *pposRecord = &posRecord;
	errorCode = SetSensorParameter((short)sensorNum, SENSOR_OFFSET, pposRecord, sizeof(posRecord));

	return errorCode;
}

DLLIMPORT int setHemisphere(int sensorNum, int *hemisphereType) {
	int errorCode = -1;

	HEMISPHERE_TYPE htype = FRONT;
	if (*hemisphereType == 1) {
		htype = BACK;
	}
	else if (*hemisphereType == 2) {
		htype = TOP;
	}
	else if (*hemisphereType == 3) {
		htype = BOTTOM;
	}
	else if (*hemisphereType == 4) {
		htype = LEFT;
	}
	else if (*hemisphereType == 5) {
		htype = RIGHT;
	}

	HEMISPHERE_TYPE *phtype = &htype;
	errorCode = SetSensorParameter((short)sensorNum, HEMISPHERE, phtype, sizeof(htype));

	return errorCode;
}

DLLIMPORT int setFilterACWideNotch(int sensorNum, int *filterOnOff){
	int errorCode = -1;

	errorCode = SetSensorParameter((short)sensorNum, FILTER_AC_WIDE_NOTCH, &(*filterOnOff), sizeof(int));

	return errorCode;
}

DLLIMPORT int setFilterACNarrowNotch(int sensorNum, int *filterOnOff) {
	int errorCode = -1;

	errorCode = SetSensorParameter((short)sensorNum, FILTER_AC_NARROW_NOTCH, &(*filterOnOff), sizeof(int));

	return errorCode;
}

DLLIMPORT int setFilterDCAdaptive(int sensorNum, double *value) {
	int errorCode = -1;

	errorCode = SetSensorParameter((short)sensorNum, FILTER_DC_ADAPTIVE, value, sizeof(double));

	return errorCode;
}

DLLIMPORT int setFilterAlphaAdaptive(int sensorNum, int *alphaMax, int *alphaMin, int *noiseVm, int *alphaOn) {
	int errorCode = -1;

	ADAPTIVE_PARAMETERS buffer, *pbuffer = &buffer;
	buffer.alphaMax[0] = (USHORT)alphaMax[0];
	buffer.alphaMax[1] = (USHORT)alphaMax[1];
	buffer.alphaMax[2] = (USHORT)alphaMax[2];
	buffer.alphaMax[3] = (USHORT)alphaMax[3];
	buffer.alphaMax[4] = (USHORT)alphaMax[4];
	buffer.alphaMax[5] = (USHORT)alphaMax[5];
	buffer.alphaMax[6] = (USHORT)alphaMax[6];
	buffer.alphaMin[0] = (USHORT)alphaMin[0];
	buffer.alphaMin[1] = (USHORT)alphaMin[1];
	buffer.alphaMin[2] = (USHORT)alphaMin[2];
	buffer.alphaMin[3] = (USHORT)alphaMin[3];
	buffer.alphaMin[4] = (USHORT)alphaMin[4];
	buffer.alphaMin[5] = (USHORT)alphaMin[5];
	buffer.alphaMin[6] = (USHORT)alphaMin[6];
	buffer.vm[0] = (USHORT)noiseVm[0];
	buffer.vm[1] = (USHORT)noiseVm[1];
	buffer.vm[2] = (USHORT)noiseVm[2];
	buffer.vm[3] = (USHORT)noiseVm[3];
	buffer.vm[4] = (USHORT)noiseVm[4];
	buffer.vm[5] = (USHORT)noiseVm[5];
	buffer.vm[6] = (USHORT)noiseVm[6];
	buffer.alphaOn = *alphaOn;

	errorCode = SetSensorParameter((short)sensorNum, FILTER_ALPHA_PARAMETERS, pbuffer, sizeof(buffer));


	return errorCode;
}

DLLIMPORT int setFilterLargeChange(int sensorNum, int *filterOnOff) {
	int errorCode = -1;

	BOOL filter = *filterOnOff == 1;
	BOOL *pfilter = &filter;
	errorCode = SetSensorParameter((short)sensorNum, FILTER_LARGE_CHANGE, pfilter, sizeof(filter));

	return errorCode;
}


// SetTransmitter expanded:
DLLIMPORT int setTxReferenceFrame(int transmitterNum, double *transmitterANG, int *transmitterXYZOn) {
	int errorCode = -1;

	DOUBLE_ANGLES_RECORD aer, *paer = &aer;
	aer.a = transmitterANG[0] / M_DEG2RAD;
	aer.e = transmitterANG[1] / M_DEG2RAD;
	aer.r = transmitterANG[2] / M_DEG2RAD;
	
	errorCode = SetTransmitterParameter((short)transmitterNum, REFERENCE_FRAME, paer, sizeof(aer));

	BOOL buffer = *transmitterXYZOn == 1;
	BOOL *pBuffer = &buffer;
	if (errorCode == BIRD_ERROR_SUCCESS) {
		errorCode = SetTransmitterParameter((short)transmitterNum, XYZ_REFERENCE_FRAME, pBuffer, sizeof(buffer));
	}
	
	return errorCode;
}


