function SkillCard({name, level}){
    return(
        <div className="rounded-2x1 bg-white/5 backdrop-blur-md border border-white/10 p-6 transition-all duration-300 hover:scale-105 hover:border-cyan-400/40 hover:bg-white/10">
            <h3 className="text-x1 font-bold">
                {name}
            </h3>
            <p className="text-gray-400 mt-2">
                {level}
            </p>
        </div>

    );
}
export default SkillCard;