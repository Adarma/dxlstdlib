void clearOleArgs () { 
    OleAutoArgs x = null; 
    if (find (gsk_stdlib_globals_, "oleHelpers.inc_args", x)) { if (!null x) delete x }
}

// oleArgs singleton
OleAutoArgs oleArgs () { 
    clearOleArgs(); 
    OleAutoArgs x = create OleAutoArgs;
    put (gsk_stdlib_globals_, "oleHelpers.inc_args", x, true)
    return x
}

void checkOLE (string s) { if (!null s) raiseError ("OLE Error in " (getCaller 3) "\ncalled from: " (getCaller 4) "\n", s) }

// enable fast creation of oleArgument lists
Array named (string argName, string     argVal) { Array v = create (1,3); put(v, "string", 0,0); put (v, argName, 0, 1); put (v, argVal, 0, 2); return  v }
Array named (string argName, int        argVal) { Array v = create (1,3); put(v, "int"   , 0,0); put (v, argName, 0, 1); put (v, argVal, 0, 2); return  v }
Array named (string argName, bool       argVal) { Array v = create (1,3); put(v, "bool"  , 0,0); put (v, argName, 0, 1); put (v, argVal, 0, 2); return  v }
Array named (string argName, OleAutoObj argVal) { Array v = create (1,3); put(v, "OLE"   , 0,0); put (v, argName, 0, 1); put (v, argVal, 0, 2); return  v }

OleAutoArgs ::<-(OleAutoArgs x, int    a) { put(x, a); return x }
OleAutoArgs ::<-(OleAutoArgs x, string a) { put(x, a); return x }
OleAutoArgs ::<-(OleAutoArgs x, bool   a) { put(x, a); return x }
OleAutoArgs ::<-(OleAutoArgs x, OleAutoObj a) { put(x, a); return x }

OleAutoArgs ::<-(OleAutoArgs x, Array ar) {    
    string argType = (string get(ar, 0,0)); 
    string argName = (string get(ar, 0,1)); 
    if (argType == "string") {string     s = (string     get(ar, 0,2)); put (x, argName, s); }
    if (argType == "int"   ) {int        s = (int        get(ar, 0,2)); put (x, argName, s); }
    if (argType == "bool"  ) {bool       s = (bool       get(ar, 0,2)); put (x, argName, s); }
    if (argType == "OLE"   ) {OleAutoObj s = (OleAutoObj get(ar, 0,2)); put (x, argName, s); }
    return x; 
}

